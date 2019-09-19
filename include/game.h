#pragma once
#include <iostream>
#include "player.h"


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

