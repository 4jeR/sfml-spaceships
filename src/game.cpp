#include "game.h"

Game::Game(){
    
}

Game::~Game(){
    delete _window;
}


void Game::run()noexcept{
    this->render();
    this->update();
}

void Game::render()noexcept{
    _window = new sf::RenderWindow(sf::VideoMode(800, 600), "Spaceships");

    
}

void Game::update()noexcept{
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
