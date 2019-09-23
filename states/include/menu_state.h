#pragma once
#include "state.h"
#include "button.h"
#include <array>
#include "game_state.h"

class MenuState : public State{
public:
    MenuState(sf::RenderWindow* window);
    ~MenuState();

    void UpdateState(std::stack<State*>& states, sf::RenderWindow* window) noexcept override;
    void Render() noexcept override;
   
    int Cooldown()const noexcept;
private:
    void InitState(std::stack<State*>& states, sf::RenderWindow* window)noexcept override;

    std::array<Button*, 5> menu_buttons;
    long unsigned int selected_button;
    int cooldown;
};