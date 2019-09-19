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

    void Run() noexcept;
private:
    void Init() noexcept;
    void Render() noexcept;
    void Update() noexcept;

    sf::RenderWindow* _window;
};