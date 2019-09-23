#include "menu_state.h"

MenuState::MenuState(sf::RenderWindow* window)
:State(window),selected_button(0),cooldown(121)
{
    
}

MenuState::~MenuState(){
    // delete all buttons
    for(auto& button : menu_buttons)
        delete button;
    
    

}


void MenuState::Render() noexcept {
    for(auto& button:menu_buttons){
        _window -> draw(*button->GetShape());
        _window -> draw(*button->GetText());
    }

}

void MenuState::InitState(std::stack<State*>& states, sf::RenderWindow* window)noexcept {
    std::cout << "entering menu state!"<<std::endl;
    std::cout << "menu InitState: states stack size -> " << states.size() << std::endl;
    menu_buttons[0] = new Button(40, 200, " start game");
    menu_buttons[1] = new Button(90, 300, "multiplayer");
    menu_buttons[2] = new Button(40, 400, "   options");
    menu_buttons[3] = new Button(90, 500, " how to play");
    menu_buttons[4] = new Button(40, 600, "  quit game");
}


int MenuState::Cooldown()const noexcept{
    return cooldown;
}

void MenuState::UpdateState(std::stack<State*>& states, sf::RenderWindow* window) noexcept {
    // menu choosing
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
    // check for closing menu
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
        switch(selected_button){
            case 0:
                std::cout << "case 0 pre gamestate push: states stack size -> " << states.size() << std::endl;
                states.push(new GameState(window));
                /**
                 * TODO:
                 *      states.top() now is NOT deleted somehow
                 * 
                 *      so each run-time sequence: 
                 *      [start game] -> [enter] -> [escape]
                 *      works fine visually, but causes 24 bytes leak
                */
            break;

            case 4:
                delete this;
                states.pop();
                std::cout << "case 4: states stack size -> " << states.size() << std::endl;
            break;
        }
    }

    
}


