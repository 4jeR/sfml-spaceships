#pragma once
#include "state.h"
#include "button.h"
#include <array>

class MenuState : public State{
public:
    MenuState(sf::RenderWindow* window);
    ~MenuState();

    void Render() noexcept override;
    void UpdateState() noexcept override;
    void InitState()noexcept override;
    bool CheckForQuit()noexcept override;
private:
    std::array<Button*, 5> menu_buttons;
};