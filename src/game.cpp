#include "game.h"

float Game::deltaTime;

sf::RenderWindow* Game::window;
Player* Game::player;
std::vector<Object*> Game::objects;
std::stack<State*> Game::states;

sf::Event Game::event;
sf::Clock Game::dtclock;

const int Game::WINDOWX;
const int Game::WINDOWY;

Game::Game(){
    Init();
}
Game::~Game(){
    delete window;
    delete player;
    FreeMemory(objects);
    FreeMemory(states);
}
void Game::Run()noexcept{
    while (window -> isOpen())
    {
        Render(objects);
        UpdateAll();
    }
}
void Game::Init() noexcept{
    window = new sf::RenderWindow(sf::VideoMode(WINDOWX, WINDOWY), "Spaceships");
    player = Player::InstantiatePlayer(static_cast<float>(WINDOWX) / 2, static_cast<float>(WINDOWY) / 2, window);
}
void Game::Render(const std::vector<Object*>& objVec)noexcept{
    window -> clear();
    window -> draw(*player->GetShape());
    window -> draw(*player->GetDot());
    for(auto& obj : objVec){
        window -> draw(*obj->GetShape());
    }
    std::cout << "Current objects count -> " << objects.size() << std::endl;
    window -> display();
}

void Game::UpdateAll()noexcept{
    UpdateDeltaTime();
    while (window -> pollEvent(event)){
        if (event.type == sf::Event::Closed)
            window -> close();
        else if(event.type == sf::Event::Resized){
            window ->setSize(sf::Vector2u(WINDOWX, WINDOWY));
            
        }
            
    }
    UpdatePlayer();
    UpdateObjects();
}
void Game::UpdateDeltaTime()noexcept{
    deltaTime = dtclock.restart().asSeconds() / 1000.f;
}
void Game::InstantiateObject(Object* newObj)noexcept{
    objects.push_back(newObj);
}
void Game::FreeMemory(std::vector<Object*>& objVec){
    for(auto& obj : objVec){
        delete obj;
        std::cout << "Deleting obj -freememory from game!" << std::endl;
    }
}
void Game::FreeMemory(std::stack<State*>& statesStack){
    while(!statesStack.empty()){
        delete statesStack.top();
        std::cout << "Deleting state -freememory from game!" << std::endl;
        statesStack.pop();
    }
}
void Game::UpdatePlayer()noexcept{
    
    player -> UpdateAll();
    
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && player-> Cooldown() > 500){
        objects.push_back(player -> Shot());
        player->GetCooldown() = 0;
    }
}

void Game::UpdateObjects()noexcept{
    for(auto& obj : objects){
        obj -> UpdateAll();
    }
}