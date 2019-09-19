#include "game.h"

float Game::deltaTime;
int Game::objectsCount = 0;

sf::RenderWindow* Game::window;
Player* Game::player;
std::vector<Object*> Game::objects;


sf::Event Game::event;
sf::Clock Game::dtclock;

Game::Game(){
    Init();
}

Game::~Game(){
    delete window;
    delete player;
}


void Game::Run()noexcept{
    while (window -> isOpen())
    {
        UpdateDeltaTime();
        Render();
        Update();
    }
}

void Game::Init() noexcept{
    window = new sf::RenderWindow(sf::VideoMode(800, 600), "Spaceships");
    player = new Player(400, 300, window);
}


void Game::Render()noexcept{
    window -> clear();
    window -> display();
}

void Game::Update()noexcept{
    while (window -> pollEvent(event)){
        if (event.type == sf::Event::Closed)
            window -> close();
    }
}

void Game::UpdateDeltaTime()noexcept{
    deltaTime = dtclock.restart().asSeconds() / 1000.f;
}


void Game::InstantiateObject(Object* newObj)noexcept{
    objects.push_back(newObj);
    ++objectsCount;
}