#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Game{
public:
    Game();
    ~Game();

    static void Run() noexcept;
    static void UpdateDeltaTime()noexcept;
    static void Render() noexcept;
    static void Update() noexcept;
private:
    static void Init() noexcept;

    static float _dTime;
    static sf::RenderWindow* _window;
    static sf::Event _event;
    static sf::Clock _clock;
};

