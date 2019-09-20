#include "game.h"

float Game::deltaTime;
int Game::objectsCount = 0;

sf::RenderWindow* Game::window;
Player* Game::player;
std::vector<Object*> Game::objects;
std::stack<State*> Game::states;

sf::Event Game::event;
sf::Clock Game::dtclock;

Game::Game(){
    Init();
}

Game::~Game(){
    delete window;
    std::cout << "Deleting window from game!!" << std::endl;
    delete player;
    std::cout << "Deleting player from game!" << std::endl;
    FreeMemory(objects);
    FreeMemory(states);
}


void Game::Run()noexcept{
    while (window -> isOpen())
    {
        Render(objects);
        Update();
    }
}

void Game::Init() noexcept{
    window = new sf::RenderWindow(sf::VideoMode(800, 600), "Spaceships");
    std::cout << "Allocate memory for window from game::Init!" << std::endl;
    player = new Player(400, 300, window);
    std::cout << "Allocate memory for player from game::Init!" << std::endl;
}


void Game::Render(const std::vector<Object*>& objVec)noexcept{
    window -> clear();
    window -> draw(*player->GetShape());
    for(auto& obj : objVec){
        window -> draw(*obj->GetShape());
    }
    window -> display();
}

void Game::Update()noexcept{
    UpdateDeltaTime();
    while (window -> pollEvent(event)){
        if (event.type == sf::Event::Closed)
            window -> close();
    }
    UpdatePlayer();
}

void Game::UpdateDeltaTime()noexcept{
    deltaTime = dtclock.restart().asSeconds() / 1000.f;
}


void Game::InstantiateObject(Object* newObj)noexcept{
    objects.push_back(newObj);
    ++objectsCount;
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
    player -> GetCooldown()++;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
        player -> MoveInY(-0.1f);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
        player -> MoveInY(0.1f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
        player -> MoveInX(-0.1f);
    } 
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
        player -> MoveInX(0.1f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && player-> Cooldown() > 1000){
        objects.push_back(player -> Shot());
        player->GetCooldown() = 0;
    }
}