#pragma once
#include <iostream>
#include "player.h"
#include <vector>

class Game{
public:
    Game();
    ~Game();
    
    static void Run() noexcept;
    static void UpdateDeltaTime()noexcept;
    static void Render() noexcept;
    static void Update() noexcept;
    static void InstantiateObject(Object* newObj)noexcept;
private:
    static void Init() noexcept;

    static float deltaTime;
    static int objectsCount;

    static sf::Event event;
    static sf::Clock dtclock;

    static sf::RenderWindow* window;
    static Player* player;
    static std::vector<Object*> objects;
};

