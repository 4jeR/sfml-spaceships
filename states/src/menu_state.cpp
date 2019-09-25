#include "menu_state.h"

MenuState::MenuState(std::array<State*, 3>& states, sf::RenderWindow* window)
:State(window),selected_button(0),cooldown(121)
{
    InitState(states);
    if(!_sound_buffer.loadFromFile("../audio/menu-switch.wav")){

    }

    if (!_menutexture.loadFromFile("../img/background.jpg")){
       
    }
    _sprite.setTexture(_menutexture);
    _sound.setBuffer(_sound_buffer);
    _sound.setVolume(70);
}

MenuState::~MenuState(){
    for(auto& button : menu_buttons)
        delete button;
}



void MenuState::Render() noexcept {
    _window->draw(_sprite);
    for(auto& button:menu_buttons){
        _window -> draw(*button->GetShape());
        _window -> draw(*button->GetText());
    }

}

void MenuState::InitState([[maybe_unused]] std::array<State*, 3>& states)noexcept {
    menu_buttons[0] = new Button(90, 150, " start game");
    RotateButton(menu_buttons[0], true);
    menu_buttons[1] = new Button(140, 270, "multiplayer");
    menu_buttons[2] = new Button(90, 390, "   options");
    menu_buttons[3] = new Button(140, 510, "  quit game");
}


int MenuState::Cooldown()const noexcept{
    return cooldown;
}

void MenuState::UpdateState([[maybe_unused]] std::array<State*, 3>& states,long unsigned int& current_state) noexcept {
    ++cooldown;
    long unsigned int prev = selected_button;
    
    if(cooldown > 100){
        cooldown = 0;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && selected_button > 0){
            --selected_button; 
            _sound.play();
            RotateButton(menu_buttons[selected_button], true);
            RotateButton(menu_buttons[prev],false);
        }
            
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)  && selected_button < menu_buttons.max_size()-1){
            ++selected_button;
            _sound.play();
            RotateButton(menu_buttons[selected_button], true);
            RotateButton(menu_buttons[prev],false);
        }

        menu_buttons[prev]->GetShape()->setFillColor(sf::Color::Transparent);
        menu_buttons[selected_button]->GetShape()->setFillColor(sf::Color::Blue);
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
        switch(selected_button){
            case 0:
                current_state = 1;
            break;

            case 3:
                _sound.play();
                _window->close();
            break;
        }
    }
}


void MenuState::RotateButton(Button* button, bool clockwise )noexcept{
    
    if(clockwise){
       button->GetShape()->rotate(5.0f);
       button->GetText()->rotate(5.0f);
    }   
    else if(!clockwise){
        button->GetShape()->rotate(-5.0f);
        button->GetText()->rotate(-5.0f);
    }
}