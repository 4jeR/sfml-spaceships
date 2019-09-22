#include "state.h"


State::State(sf::RenderWindow* window)
:_window(window),_quitState(false)
{
    
}

State::~State(){
    // STATE MUSTN'T DELETE  _window  POINTER
}