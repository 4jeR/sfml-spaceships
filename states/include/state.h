#pragma once
#include "sfml_headers.h"
#include <vector>
#include <iostream>
#include <unistd.h>

class State{
public:
    State(sf::RenderWindow* window);
    virtual ~State();
    virtual void Render() noexcept = 0;
    virtual void UpdateState() noexcept = 0;
    virtual void InitState()noexcept = 0;
    virtual bool CheckForQuit()noexcept = 0;
protected:
    sf::RenderWindow* _window;
    bool _quitState;
};