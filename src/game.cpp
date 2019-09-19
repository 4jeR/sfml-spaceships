#include "game.h"

float Game::_dTime;
sf::RenderWindow* Game::_window;
sf::Event Game::_event;
sf::Clock Game::_clock;

Game::Game(){
    
}

Game::~Game(){
    delete _window;
}


void Game::Run()noexcept{
    Init();
    while (_window -> isOpen())
    {
        Render();
        Update();
    }
}

void Game::Init() noexcept{
    _window = new sf::RenderWindow(sf::VideoMode(800, 600), "Spaceships");
}


void Game::Render()noexcept{
    _window -> clear();
    _window -> display();
}

void Game::Update()noexcept{
    while (_window -> pollEvent(_event)){
        if (_event.type == sf::Event::Closed)
            _window -> close();
    }
}

void Game::UpdateDeltaTime()noexcept{
    _dTime = _clock.restart().asSeconds() / 1000.f;
}
