#include "game_state.h"

Player* GameState::player;
std::vector<Object*> GameState::objects;

GameState::GameState( sf::RenderWindow* window)
:State(window)
{
    if(!player)
        player = Player::InstantiatePlayer(static_cast<float>(_window->getSize().x) / 2, static_cast<float>(_window->getSize().y) / 2, _window);
    tracker = new StatsTracker();
}


GameState::~GameState(){   
    delete tracker;     
    FreeMemory();
}


void GameState::Render() noexcept {
    _window -> draw(*player->GetShape());
    _window -> draw(*player->GetDot());
    for(auto& obj : objects){
        _window -> draw(*obj->GetShape());  
    }
    tracker->UpdateStats(player);
    _window -> draw(*tracker->Text());
}



void GameState::FreeMemory(){
    for(long unsigned int i = 0; i < objects.size(); ++i){
        delete objects.at(i);
        objects.erase(objects.begin()+static_cast<int>(i)); 
    }
}

void GameState::UpdatePlayer()noexcept{
    player -> UpdateAll();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && player-> Cooldown() > 250){
        objects.push_back(player -> Shot());
        player->GetCooldown() = 0;
    }
}

void GameState::UpdateObjects()noexcept{
    for(auto& obj : objects){
        obj -> UpdateAll();
    }
}


void GameState::InitState([[maybe_unused]] std::stack<State*>& states,[[maybe_unused]]  sf::RenderWindow* window)noexcept{
    std::cout << "entering game state!"<<std::endl;

    std::cout << "states stack size -> " << states.size() << std::endl;
    player = Player::InstantiatePlayer(static_cast<float>(_window->getSize().x) / 2, static_cast<float>(_window->getSize().y) / 2, _window);
}


void GameState::UpdateState(std::stack<State*>& states, sf::RenderWindow* window) noexcept {
    UpdatePlayer();
    UpdateObjects();
    FreeDestroyedObjects();
    

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)){
        delete this;
        states.pop();
        std::cout << "after clicking escape, states stack size -> " << states.size() << std::endl;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P)){
        
        states.push(new PauseState(states, window));
        std::cout << "after clicking pause, states stack size -> " << states.size() << std::endl;
    }
}



void GameState::FreeDestroyedObjects(){
    int i = 0;
    for(auto& obj: objects){
        if(obj && obj -> IsDestroyed()){
            delete obj;
            objects.erase(objects.begin() + i);
            ++i;
        }
    }
}
