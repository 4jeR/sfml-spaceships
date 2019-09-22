#pragma once
#include "state.h"

class MenuState : public State{
public:
    MenuState(sf::RenderWindow);
    ~MenuState();

    virtual void Render() noexcept = 0;
    virtual void UpdateState() noexcept = 0;
    virtual void InitState()noexcept = 0;
    virtual bool CheckForQuit()noexcept = 0;

};