#include "player.h"



Player::Player(float x, float y, sf::RenderWindow* winptr)
:Object(x, y, winptr),_cooldown(0)
{
    _shape = new sf::CircleShape(25.0f, 3);
    std::cout << "Allocate memory for shape from Player::Player!" << std::endl;
    _shape -> setPosition(x, y);
    _shape -> setFillColor(sf::Color::Transparent);
    _shape -> setOutlineThickness(1.5f);
    _shape -> setOutlineColor(sf::Color::Green);
}


Player::~Player(){
    delete _shape;
    std::cout << "Deleting shape from Playerclass!" << std::endl;
}


Missile* Player::Shot()noexcept{
    _missile = new Missile(_x, _y + 15.0f, _window);
    return _missile;
}

Player* Player::InstantiatePlayer(float x, float y, sf::RenderWindow* window){
    std::cout << "Allocate memory for Player from Player:InstantiatePlayer!" << std::endl;
    return new Player(x, y, window);
}

void Player::MoveInX(float value)noexcept{
    _x += value;
    _shape->move(value, 0.0f);
}


void Player::MoveInY(float value)noexcept{
    _y += value;
    _shape->move(0.0f, value);
}


Player& Player::operator=(const Player& rhs){
    Object::operator=(rhs);
    _lives = rhs._lives;
    
    return *this;
}

void Player::Draw(const sf::Drawable& obj)const{
    _window -> draw(obj);
}

sf::Shape* Player::GetShape(){
    return _shape;
}

int& Player::GetLives()noexcept{
    return _lives;
}

int& Player::GetCooldown() noexcept{
    return _cooldown;
}

int Player::Cooldown()const noexcept{
    return _cooldown;
}

int Player::Lives()const noexcept{
    return _lives;
}