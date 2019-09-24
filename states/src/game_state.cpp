#include "game_state.h"

Player* GameState::player;
std::vector<Object*> GameState::objects;
int GameState::enemies_count = 0;
sf::RenderWindow* GameState::window_ptr;


GameState::GameState(std::array<State*, 3>& states, sf::RenderWindow* window)
:State(window)
{
    srand(time(NULL));
    window_ptr = window;
    InitState(states);
}


GameState::~GameState(){   
    delete tracker; 
    for(auto& obj: objects){
        delete obj;
    }    
}


void GameState::FreeDestroyedObjects(){
    int i = 0;
    for(auto& obj: objects){
        if(obj->IsDestroyed()){
            delete obj;
            objects.erase(objects.begin()+i);
            ++i;
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

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && player-> Cooldown() > 250){
        objects.push_back(player -> Shot());
        player->GetCooldown() = 0;
    }
}

void GameState::UpdateObjects()noexcept{
    // SPAWN ENEMIES
    if(enemies_count <= 2){
        float randX = static_cast<float>(std::rand()%400+1);
        float randY = static_cast<float>(std::rand()%700+1);
        objects.push_back(Enemy::InstantiateEnemy(randX, randY, window_ptr));
        ++enemies_count;
    }
    

    for(auto& obj : objects){
        obj -> UpdateAll();
    }
}


void GameState::InitState(std::array<State*, 3>& states)noexcept{
    std::cout << "entering game state!"<<std::endl;
    std::cout << "states stack size -> " << states.size() << std::endl;
    player = Player::InstantiatePlayer(static_cast<float>(_window->getSize().x) / 2, static_cast<float>(_window->getSize().y) / 2, _window);
    tracker = new StatsTracker();
}


void GameState::UpdateState([[maybe_unused]] std::array<State*, 3>& states,long unsigned int& current_state) noexcept {
    UpdatePlayer();
    UpdateObjects();
    // FreeDestroyedObjects();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
        current_state = 0;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P))
        current_state = 2;

}


