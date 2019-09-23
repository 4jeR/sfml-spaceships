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
    virtual void UpdateState(std::stack<State*>& states, sf::RenderWindow* window) noexcept = 0;
    virtual void InitState(std::stack<State*>& states, sf::RenderWindow* window)noexcept = 0;
    virtual bool ShouldQuit()const noexcept;
protected:
    sf::RenderWindow* _window;
    bool _quitState;
};