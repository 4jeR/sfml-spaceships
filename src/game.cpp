#include "game.h"

Game::Game(){
    
}

Game::~Game(){
    delete _window;
}


void Game::Run()noexcept{
    Init();
    Render();
    Update();
}

void Game::Init() noexcept{
    _window = new sf::RenderWindow(sf::VideoMode(800, 600), "Spaceships");

}


void Game::Render()noexcept{
   
    
}

void Game::Update()noexcept{
    while (_window -> isOpen())
    {
        sf::Event event;
        while (_window -> pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                _window -> close();
        }

        _window -> clear();
        _window -> display();
    }
}
