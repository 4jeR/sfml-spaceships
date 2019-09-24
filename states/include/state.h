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
    virtual void UpdateState(std::array<State*, 3>& states,long unsigned int& current_state) noexcept = 0;
    virtual bool ShouldQuit()const noexcept;
    virtual void InitState(std::array<State*, 3>& states)noexcept = 0;
protected:
    sf::RenderWindow* _window;
    bool _quitState;
};