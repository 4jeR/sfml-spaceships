#include "game_state.h"

Player* GameState::player;
std::vector<Object*> GameState::objects;


GameState::GameState(sf::RenderWindow* window)
:State(window)
{
  
}


GameState::~GameState(){
    delete player;
    FreeMemory();

}


void GameState::Render() noexcept {
    _window -> draw(*player->GetShape());
    _window -> draw(*player->GetDot());
    for(auto& obj : objects){
        _window -> draw(*obj->GetShape());  
    }
}



void GameState::FreeMemory(){
    for(auto& obj : objects){
        delete obj;
        std::cout << "Deleting obj - freememory application destructor!" << std::endl;
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


void GameState::InitState()noexcept{
    std::cout << "entering game state!"<<std::endl;
    player = Player::InstantiatePlayer(static_cast<float>(_window->getSize().x) / 2, static_cast<float>(_window->getSize().y) / 2, _window);
}


void GameState::UpdateState() noexcept {
    UpdatePlayer();
    UpdateObjects();
    FreeDestroyedObjects();
}

bool GameState::CheckForQuit()noexcept {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::T))
        _quitState = true;
    
    if(_quitState){

        std::cout << "quitting gamestate!" << std::endl;
    }
    return _quitState;
}


void GameState::FreeDestroyedObjects(){
    for(int i = 0; i < static_cast<int>(objects.size()); ++i){
        if(objects.at(static_cast<long unsigned int>(i))->IsDestroyed()){
            delete objects.at(static_cast<long unsigned int>(i));
            objects.erase(objects.begin()+i);
        }
    }
}
