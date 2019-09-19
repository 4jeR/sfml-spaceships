#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

class Game{
public:
    Game();
    ~Game();

    void run()noexcept;
private:
    void render()noexcept;
    void update()noexcept;

    sf::RenderWindow* _window;
};