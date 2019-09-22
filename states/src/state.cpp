#include "state.h"


State::State(sf::RenderWindow* window)
:_window(window)
{
    
}

State::~State(){
    // STATE MUSTN'T DELETE  _window  POINTER
}