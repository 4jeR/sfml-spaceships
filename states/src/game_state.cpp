#include "game_state.h"

Player* GameState::player;
std::vector<Object*> GameState::objects;
int GameState::enemies_count = 0;
sf::RenderWindow* GameState::window_ptr;


GameState::GameState(std::array<State*, 5>& states, sf::RenderWindow* window)
:State(window)
{
    srand(time(NULL));
    window_ptr = window;
    InitState(states);

    if(!_sound_buffer[0].loadFromFile("../audio/pause.wav")){}
    _sound[0].setBuffer(_sound_buffer[0]);
    _sound[0].setVolume(40.0f);
    _sound[0].setPitch(0.8f);

    if(!_sound_buffer[1].loadFromFile("../audio/failure.wav")){}

    _sound[1].setBuffer(_sound_buffer[1]);
    _sound[1].setVolume(60.0f);
}


GameState::~GameState(){   
    delete tracker; 
    for(auto& obj: objects){
        delete obj;
    }    
}


void GameState::FreeDestroyedObjects(){                
    for(auto it = objects.begin(); it != objects.end(); ){
        if((*it)->IsDestroyed()){
            delete *it;
            it = objects.erase(it);
        }
        else{
            ++it;
        }
    }
}


void GameState::Render() noexcept {
    _window -> draw(*player->GetShape());
    _window -> draw(*player->GetDot());
    for(auto& obj : objects){
        if(!obj->IsDestroyed())
            _window -> draw(*obj->GetShape());  
    }
    tracker->UpdateStats(player);
    _window -> draw(*tracker->LivesText());
    _window -> draw(*tracker->ScoreText());
}




void GameState::UpdatePlayer()noexcept{
    player -> UpdateAll();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && player-> Cooldown() > 334){
        objects.push_back(player -> Shoot());
        player->GetCooldown() = 0;
    }
}

void GameState::UpdateObjects()noexcept{
    // SPAWN ENEMIES
    if(enemies_count <= 2){
        float randX = static_cast<float>(std::rand()%900+1);
        float randY = static_cast<float>(std::rand()%700+1);
        objects.push_back(Enemy::InstantiateEnemy(randX, randY, window_ptr));
        ++enemies_count;
    }
    
    bool destroyed = true;
    for(auto& obj : objects){
        obj -> UpdateAll();
        for(auto& other : objects){
            if(!(obj == other) && obj->OnCollide(other)){
                if(!destroyed){
                    destroyed=true;
                    player->AddScore(20);
                    --enemies_count;
                }
                    
            }
        }
    }
    for(auto& obj : objects){
        player->OnCollide(obj);
    }
}


void GameState::InitState([[maybe_unused]] std::array<State*, 5>& states)noexcept{
    player = new Player(static_cast<float>(_window->getSize().x) / 2, static_cast<float>(_window->getSize().y) / 2, _window);
    tracker = new StatsTracker();
}


void GameState::UpdateState([[maybe_unused]] std::array<State*, 5>& states,long unsigned int& current_state) noexcept {
    UpdatePlayer();
    UpdateObjects();
    FreeDestroyedObjects();
    CheckForGameOver(states, current_state);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)){
        _sound[0].play();   
        current_state = 2;
    }
    

}


void GameState::CheckForGameOver([[maybe_unused]] std::array<State*, 5>& states,long unsigned int& current_state)noexcept{
    if(player->Lives() <= 0){
        _sound[1].play(); 
        current_state = 4;
    }
}  