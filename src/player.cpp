#include "player.h"



Player::Player(float x, float y, sf::RenderWindow* winptr)
:_x(x),_y(y), _window(winptr)
{
    
}


Player::~Player(){
    delete _window;
}


void Player::Shot()noexcept{
    
}

Player* Player::InstantiatePlayer(float x, float y, sf::RenderWindow* window){
    return new Player(x, y, window);
}

void Player::MoveInX(float value)noexcept{
    _x += value;
}


void Player::MoveInY(float value)noexcept{
    _y += value;
}

