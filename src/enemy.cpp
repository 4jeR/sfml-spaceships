#include "enemy.h"

Enemy::Enemy(float x, float y, sf::RenderWindow* winptr)
:Object(x, y, winptr),_radius(12.0f)
{
    _shape = new sf::CircleShape(_radius, 5);
    std::cout << "Allocate memory for shape from Enemy::enemy!" << std::endl;
    _shape -> setPosition(_x, _y);
    _shape -> setFillColor(sf::Color::Transparent);
    _shape -> setOutlineThickness(2.0f);
    _shape -> setOutlineColor(sf::Color::Red);
}

Enemy::~Enemy(){
    delete _shape;
}



float Enemy::CurrentSpeed()const noexcept{
    return _currentSpeed;
}

float& Enemy::GetCurrentSpeed()noexcept{
    return _currentSpeed;
}

float Enemy::X()const noexcept{
    return _x;
}

float& Enemy::GetX()noexcept{
    return _x;
}

float Enemy::Y()const noexcept{
    return _y;
}

float& Enemy::GetY()noexcept{
    return _y;
}



void Enemy::UpdateAll() noexcept {
    UpdateTransforms();
    DisappearedFromWindow();
    /**
     * and more stuff later on ...
    */
}

sf::Shape* Enemy::GetShape() noexcept {
    return _shape;
}

void Enemy::UpdateTransforms()noexcept{
    Rotate();
}

void Enemy::Rotate()noexcept {
    
}
