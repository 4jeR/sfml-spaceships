#include "enemy.h"

Enemy::Enemy(float x, float y, sf::RenderWindow* winptr)
:Object(x, y, winptr),_radius(12.0f)
{
    std::cout << "Allocate memory for shape from Enemy::enemy!" << std::endl;
    _shape = new sf::CircleShape(_radius, 5);
    _shape -> setPosition(_x, _y);
    _shape -> setFillColor(sf::Color::Transparent);
    _shape -> setOutlineThickness(2.0f);
    _shape -> setOutlineColor(sf::Color::Red);
    _currentSpeed = 200.0f;
}

Enemy* Enemy::InstantiateEnemy(float x, float y, sf::RenderWindow* window){
    return new Enemy(x, y, window);
}


Enemy::~Enemy(){
    std::cout << "deleting enemy" <<std::endl;
    delete _shape;

}


void Enemy::UpdateAll() noexcept {
    UpdateTransforms();
    DisappearedFromWindow();
    
}

sf::Shape* Enemy::GetShape() noexcept {
    return _shape;
}

void Enemy::UpdateTransforms()noexcept{
    Rotate();
    
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
