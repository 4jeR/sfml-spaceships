#pragma once
#include "player.h"
#include "state.h"
#include "enemy.h"
#include "obj_cleaner.h"

#include <iostream>
#include <vector>
#include <stack>

class Game{
public:
    Game();
    ~Game();
    
    static void Run() noexcept;
    static void Render(const std::vector<Object*>& objects) noexcept;
    static void UpdateAll() noexcept;
private:
    static void InstantiateObject(Object* newObj)noexcept;
    static void Init() noexcept;
    static void FreeMemory(std::vector<Object*>& objVec);
    static void FreeMemory(std::stack<State*>& statesStack);
    static void UpdateDeltaTime()noexcept;
    static void UpdatePlayer()noexcept;
    static void UpdateObjects()noexcept;

    static float deltaTime;

    static sf::Event event;
    static sf::Clock dtclock;
    static const constexpr int WINDOWX = 1200;
    static const constexpr int WINDOWY = 800;
    

    static sf::RenderWindow* window;
    static Player* player;
    static std::vector<Object*> objects;
    static std::stack<State*> states;
    static ObjectCleaner cleaner;
};
