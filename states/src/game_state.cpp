#include "game_state.h"

Player* GameState::player;
std::vector<Object*> GameState::objects;

GameState::GameState(std::array<State*, 3>& states, sf::RenderWindow* window)
:State(window)
{
    InitState(states, window);
        
}


GameState::~GameState(){   
    delete tracker;     
    FreeDestroyedObjects();
}


void GameState::FreeDestroyedObjects(){
    for(auto& obj: objects)
        delete obj;
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
    for(auto& obj : objects){
        obj -> UpdateAll();
    }
}


void GameState::InitState(std::array<State*, 3>& states, sf::RenderWindow* window)noexcept{
    std::cout << "entering game state!"<<std::endl;
    std::cout << "states stack size -> " << states.size() << std::endl;
    player = Player::InstantiatePlayer(static_cast<float>(_window->getSize().x) / 2, static_cast<float>(_window->getSize().y) / 2, _window);
    tracker = new StatsTracker();
}


void GameState::UpdateState(std::array<State*, 3>& states,long unsigned int& current_state, sf::RenderWindow* window) noexcept {
    UpdatePlayer();
    UpdateObjects();
    

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)){
        // delete this;
        // states.pop();
        current_state = 0;
        std::cout << "after clicking escape, states stack size -> " << states.size() << std::endl;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P)){
        
        current_state = 2;
        std::cout << "after clicking pause, states stack size -> " << states.size() << std::endl;
    }
}


