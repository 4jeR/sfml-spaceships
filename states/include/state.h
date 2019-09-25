#pragma once
#include "sfml_headers.h"
#include <vector>
#include <iostream>
#include <unistd.h>
#include <stack>


class State{
public:
    State(sf::RenderWindow* window);
    virtual ~State();
    virtual void Render() noexcept = 0;
    virtual void UpdateState(std::array<State*, 4>& states,long unsigned int& current_state) noexcept = 0;
    virtual bool ShouldQuit()const noexcept;
    virtual void InitState(std::array<State*, 4>& states)noexcept = 0;
    int Cooldown()const noexcept;
    int& GetCooldown()noexcept;
protected:
    sf::RenderWindow* _window;
    bool _quitState;
    int _cooldown;
    int _cooldown2;
};