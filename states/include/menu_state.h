#pragma once
#include "state.h"

class MenuState : public State{
public:
    MenuState(sf::RenderWindow* window);
    ~MenuState();

    void Render() noexcept override;
    void UpdateState() noexcept override;
    void InitState()noexcept override;
    bool CheckForQuit()noexcept override;
private:
    
};