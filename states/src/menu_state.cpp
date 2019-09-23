#include "menu_state.h"

MenuState::MenuState(sf::RenderWindow* window)
:State(window)
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

void MenuState::InitState()noexcept {
    std::cout << "entering menu state!"<<std::endl;
    menu_buttons[0] = new Button(40, 300, "start game");
    menu_buttons[1] = new Button(90, 400, "multiplayer");
    menu_buttons[2] = new Button(40, 500, "options");
    menu_buttons[3] = new Button(90, 600, "about");
    menu_buttons[4] = new Button(40, 700, "quit game");
}

void MenuState::UpdateState() noexcept {
    
}




bool MenuState::CheckForQuit()noexcept {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
        _quitState = true;
    
    /**
     * NOTE:
     *      this will be replaced by logic part (logic class maybe) later on
     * 
     * */ 
    if(_quitState){

        std::cout << "quitting menustate!" << std::endl;
    }
    return _quitState;
}

