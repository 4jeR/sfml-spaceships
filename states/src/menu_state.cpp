#include "menu_state.h"

MenuState::MenuState(std::array<State*, 3>& states, sf::RenderWindow* window)
:State(window),selected_button(0),cooldown(121)
{
    InitState(states);
}

MenuState::~MenuState(){
    for(auto& button : menu_buttons)
        delete button;
}


void MenuState::Render() noexcept {
    for(auto& button:menu_buttons){
        _window -> draw(*button->GetShape());
        _window -> draw(*button->GetText());
    }

}

void MenuState::InitState([[maybe_unused]] std::array<State*, 3>& states)noexcept {
    menu_buttons[0] = new Button(40, 200, " start game");
    menu_buttons[1] = new Button(90, 300, "multiplayer");
    menu_buttons[2] = new Button(40, 400, "   options");
    menu_buttons[3] = new Button(90, 500, " how to play");
    menu_buttons[4] = new Button(40, 600, "  quit game");
}


int MenuState::Cooldown()const noexcept{
    return cooldown;
}

void MenuState::UpdateState([[maybe_unused]] std::array<State*, 3>& states,long unsigned int& current_state) noexcept {
    ++cooldown;
    long unsigned int prev = selected_button;
    if(cooldown > 100){
        cooldown = 0;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && selected_button > 0)
            --selected_button; 
            
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)  && selected_button < menu_buttons.max_size()-1){
            ++selected_button;
        }

        menu_buttons[prev]->GetShape()->setFillColor(sf::Color::Transparent);
        menu_buttons[selected_button]->GetShape()->setFillColor(sf::Color::Blue);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
        switch(selected_button){
            case 0:
                current_state = 1;
            break;

            case 4:
                _window->close();
            break;
        }
    }
}


