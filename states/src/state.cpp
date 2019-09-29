#include "state.h"



State::State(sf::RenderWindow* window)
:_window(window),_quitState(false),_cooldown(0),_cooldown2(0)
{   
}

State::~State(){
}


bool State::ShouldQuit()const noexcept{
    return _quitState;
}


int State::Cooldown()const noexcept{
    return _cooldown;
}


int& State::GetCooldown()noexcept{
    return _cooldown;
}
