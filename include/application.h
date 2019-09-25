#pragma once
#include "player.h"
#include "game_state.h"
#include "menu_state.h"
#include "options_state.h"
#include "enemy.h"

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
    static void InitStates()noexcept;
    static void FreeStatesMemory();


    static sf::Event event;
    static sf::Clock dtclock;
    static const constexpr int WINDOWX = 1200;
    static const constexpr int WINDOWY = 800;
    

    static sf::RenderWindow* window;
    static std::array<State*, 4> states;
    static long unsigned int currentState;
};
