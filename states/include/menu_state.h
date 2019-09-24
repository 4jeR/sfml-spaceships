#pragma once
#include "state.h"
#include "button.h"
#include <array>
#include "game_state.h"


class MenuState : public State{
public:
    MenuState(std::array<State*, 3>& states, sf::RenderWindow* window);
    ~MenuState();

    void UpdateState(std::array<State*, 3>& states,long unsigned int& current_state, sf::RenderWindow* window) noexcept override;
    void Render() noexcept override;
   
    void InitState(std::array<State*, 3>& states, sf::RenderWindow* window)noexcept override;
    int Cooldown()const noexcept;
private:

    std::array<Button*, 5> menu_buttons;
    long unsigned int selected_button;
    int cooldown;
};