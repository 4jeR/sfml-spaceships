#pragma once
#include "player.h"
#include "state.h"

#include <iostream>
#include <vector>
#include <stack>

class Game{
public:
    Game();
    ~Game();
    
    static void Run() noexcept;
    static void UpdateDeltaTime()noexcept;
    static void Render(const std::vector<Object*>& objects) noexcept;
    static void Update() noexcept;
    static void InstantiateObject(Object* newObj)noexcept;
private:
    static void Init() noexcept;
    static void FreeMemory(std::vector<Object*>& objVec);
    static void FreeMemory(std::stack<State*>& statesStack);
    static void UpdatePlayer()noexcept;
    static float deltaTime;
    static int objectsCount;

    static sf::Event event;
    static sf::Clock dtclock;

    static sf::RenderWindow* window;
    static Player* player;
    static std::vector<Object*> objects;
    static std::stack<State*> states;
};
