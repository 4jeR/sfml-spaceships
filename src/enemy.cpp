#include "enemy.h"

Enemy::Enemy(float x, float y, sf::RenderWindow* winptr, float radius)
:Object(x, y, winptr, radius)
{
    // std::cout << __PRETTY_FUNCTION__ << std::endl;
    _shape = new sf::CircleShape(radius, 5);
    _shape -> setPosition(_x, _y);
    _shape -> setFillColor(sf::Color::Transparent);
    _shape -> setOutlineThickness(2.0f);
    _shape -> setOutlineColor(sf::Color::Red);
    _currentSpeed = 200.0f;

    _name = "enemy";
}

Enemy* Enemy::InstantiateEnemy(float x, float y, sf::RenderWindow* winptr, float radius){
    return new Enemy(x, y, winptr, radius);
}


Enemy::~Enemy(){
    // std::cout << __PRETTY_FUNCTION__ << std::endl;
    delete _shape;
}


void Enemy::UpdateAll() noexcept {
    // UpdateTransforms();
    DisappearedFromWindow();
    
}

sf::Shape* Enemy::GetShape() noexcept {
    return _shape;
}


void Enemy::UpdateTransforms()noexcept{
    //Rotate();
    
    float byX = 0.001f * _currentSpeed *  static_cast<float>(std::sin(static_cast<double>(_shape->getRotation()) * M_PI / 180.0));
    float byY = 0.001f * _currentSpeed *  static_cast<float>(std::cos(static_cast<double>(_shape->getRotation()) * M_PI / 180.0));
       
    _shape -> move(byX, byY );
    _x += byX;
    _y += byY;
}

void Enemy::Rotate()noexcept {
    
    float rotateCoef =   0.25f - CalcAngularVelocity(_currentSpeed);
    _shape -> rotate(rotateCoef);
}
