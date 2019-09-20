#include "player.h"



Player::Player(float x, float y, sf::RenderWindow* winptr)
:Object(x, y, winptr)
{
    _shape = new sf::CircleShape(50.0f, 3);
    _shape -> setPosition(x, y);
    _shape -> setFillColor(sf::Color::Transparent);
    _shape -> setOutlineThickness(1.5f);
    _shape -> setOutlineColor(sf::Color::Green);
}


Player::~Player(){
    delete _shape;
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


Player& Player::operator=(const Player& rhs){
    Object::operator=(rhs);
    _lives = rhs._lives;
    
    return *this;
}

void Player::Draw(const sf::Drawable& obj)const{
    _window -> draw(obj);
}