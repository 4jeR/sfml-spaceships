#pragma once
#include "player.h"
#include "game_state.h"
#include "menu_state.h"
#include "enemy.h"
#include "obj_cleaner.h"

#include <iostream>
#include <vector>
#include <stack>

class Application{
public:
    Application();
    ~Application();
    
    static void Run() noexcept;
    static void Render() noexcept;
    static void UpdateAll() noexcept;
private:
    static void InstantiateObject(Object* newObj)noexcept;
    static void InitStates()noexcept;
    static void InitWindow()noexcept;
    static void FreeStatesMemory();
    static void UpdateDeltaTime()noexcept;

    static float deltaTime;

    static sf::Event event;
    static sf::Clock dtclock;
    static const constexpr int WINDOWX = 1200;
    static const constexpr int WINDOWY = 800;
    

    static sf::RenderWindow* window;
    static std::stack<State*> states;
    static Player* player;
};
