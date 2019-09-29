#pragma once
#include "state.h"
#include "button.h"
#include <array>
#include "game_state.h"


class MenuState : public State{
public:
    MenuState(std::array<State*, 5>& states, sf::RenderWindow* window);

    ~MenuState();

    void UpdateState(std::array<State*, 5>& states,long unsigned int& current_state) noexcept override;

    void Render() noexcept override;
   
    void InitState(std::array<State*, 5>& states)noexcept override;

    void RotateButton(Button* button, bool clockwise)noexcept;
private:
    std::array<Button*, 4> menu_buttons;

    long unsigned int selected_button;
    
    sf::SoundBuffer _sound_buffer;

    sf::Sound _sound;

    sf::Texture _menutexture;
    
    sf::Sprite _sprite;
};