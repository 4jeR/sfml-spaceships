#include "menu_state.h"

MenuState::MenuState(sf::RenderWindow* window)
:State(window)
{
    
}

MenuState::~MenuState(){
    // delete all buttons
}


void MenuState::Render() noexcept {

}

void MenuState::InitState()noexcept {
    std::cout << "entering menu state!"<<std::endl;
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

