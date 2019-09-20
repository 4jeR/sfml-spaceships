#include "game.h"

float Game::deltaTime;
int Game::objectsCount = 0;

sf::RenderWindow* Game::window;
Player* Game::player;
std::vector<Object*> Game::objects;
std::stack<State*> Game::states;

sf::Event Game::event;
sf::Clock Game::dtclock;

unsigned int Game::WINDOWX = 800;
unsigned int Game::WINDOWY = 600;

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
    window = new sf::RenderWindow(sf::VideoMode(WINDOWX, WINDOWY), "Spaceships");
    std::cout << "Allocate memory for window from game::Init!" << std::endl;
    player = new Player(static_cast<float>(WINDOWX) / 2, static_cast<float>(WINDOWY) / 2, window);
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
        else if (event.type == sf::Event::Resized)
            UpdateWindowSize();
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
        player -> MoveInY(-0.0003f * static_cast<float>(WINDOWY));
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
        player -> MoveInY(0.0003f  * static_cast<float>(WINDOWY));
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
        player -> MoveInX(-0.0002f * static_cast<float>(WINDOWX));
    } 
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
        player -> MoveInX(0.0002f  * static_cast<float>(WINDOWX));
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && player-> Cooldown() > 1000){
        objects.push_back(player -> Shot());
        player->GetCooldown() = 0;
    }
}

void Game::UpdateWindowSize()noexcept{
    WINDOWX = window -> getSize().x;
    WINDOWY = window -> getSize().y;
}