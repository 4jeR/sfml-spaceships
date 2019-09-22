#include "game_state.h"

Player* GameState::player;
std::vector<Object*> GameState::objects;

GameState::GameState(sf::RenderWindow* window)
:State(window)
{

}


GameState::~GameState(){
    delete player;
    FreeMemory(objects);

}


void GameState::Render() noexcept {
    _window -> draw(*player->GetShape());
    _window -> draw(*player->GetDot());
    for(auto& obj : objects){
        _window -> draw(*obj->GetShape());  
    }
    std::cout << "Current objects count -> " << objects.size() << std::endl;

}

void GameState::UpdateState(const float& dt) noexcept {
    UpdatePlayer();
    UpdateObjects();

}

void GameState::QuitState()noexcept{

}

void GameState::FreeMemory(std::vector<Object*>& objVec){
    for(auto& obj : objVec){
        delete obj;
        std::cout << "Deleting obj -freememory from game!" << std::endl;
    }
}

void GameState::UpdatePlayer()noexcept{
    
    player -> UpdateAll();
    
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && player-> Cooldown() > 500){
        objects.push_back(player -> Shot());
        player->GetCooldown() = 0;
    }
}

void GameState::UpdateObjects()noexcept{
    for(auto& obj : objects){
        obj -> UpdateAll();
    }
}


void GameState::InitState()noexcept{
    player = Player::InstantiatePlayer(static_cast<float>(_window->getSize().x) / 2, static_cast<float>(_window->getSize().y) / 2, _window);
}