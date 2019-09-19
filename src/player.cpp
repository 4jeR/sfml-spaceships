#include "player.h"



Player::Player(float x, float y, sf::RenderWindow* winptr)
:Object(x, y, winptr)
{
    
}


Player::~Player(){
    
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

void Player::draw (sf::RenderTarget &target, sf::RenderStates states) const {
    _missile ->draw(target, states);
}

Player& Player::operator=(const Player& rhs){
    Object::operator=(rhs);
    _lives = rhs._lives;
    
    return *this;
}