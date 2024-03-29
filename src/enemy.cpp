#include "enemy.h"

Enemy::Enemy(float x, float y, sf::RenderWindow* winptr, float radius, int foreign)
:Object(x, y, winptr, radius, foreign)
{
    _shape = new sf::CircleShape(radius);
    _shape -> setPosition(_x, _y);
    _shape -> setFillColor(sf::Color::Transparent);
    _shape -> setOutlineThickness(2.0f);
    _shape -> setOutlineColor(sf::Color::Red);
    _shape -> setOrigin(radius / 2.0f, radius / 2.0f );
    _currentSpeed = 200.0f;
    _name = "enemy";
    _currentPath = 0;

    for(int i = 0; i < 4; ++i){
        _path[i].x = static_cast<float>(std::rand() % 1000 + 100);
        _path[i].y = static_cast<float>(std::rand() % 600 + 100);
    }

    if(!_sound_buffer.loadFromFile("../audio/laser-shot.wav")){}
    _sound.setBuffer(_sound_buffer);
    _sound.setVolume(30);
}


Enemy* Enemy::InstantiateEnemy(float x, float y, sf::RenderWindow* winptr, float radius, int foreign ){
    return new Enemy(x, y, winptr, radius, foreign);
}


Enemy::~Enemy(){
    delete _shape;
}


void Enemy::UpdateAll() noexcept {
    UpdateTransforms();
    DisappearedFromWindow();
}

sf::Shape* Enemy::GetShape() noexcept {
    return _shape;
}

Missile* Enemy::Shoot()noexcept{
    _sound.play();
    float byX =  1.5f * _radius * static_cast<float>(std::sin(static_cast<double>(_shape->getRotation()) * M_PI / 180.0));
    float byY = -1.5f * _radius * static_cast<float>(std::cos(static_cast<double>(_shape->getRotation()) * M_PI / 180.0));
    
    _currentSpeed -= 60.0f;
    
    _missile = new Missile(_x + byX, _y + byY, _window, _radius);
    _missile -> SetForeign(2);
    _missile -> GetShape() -> rotate(_shape -> getRotation());
    return _missile;
}

void Enemy::UpdateTransforms()noexcept{
    Rotate();
    Patrol();
}

void Enemy::Rotate()noexcept {
    float rotateCoef =   0.25f - CalcAngularVelocity(_currentSpeed);
    _shape -> rotate(rotateCoef);
}

void Enemy::Patrol()noexcept{
    float byX = 0.001f * _currentSpeed *  static_cast<float>(std::sin(static_cast<double>(_shape->getRotation()) * M_PI / 180.0));
    float byY = 0.001f * _currentSpeed *  static_cast<float>(std::cos(static_cast<double>(_shape->getRotation()) * M_PI / 180.0));
       
    _shape -> move(byX, byY );
    _x += byX;
    _y += byY;
}


sf::Vector2f Enemy::CalcDistanceTo(int idx)const noexcept{
    float xdistance = _path[idx].x - _x;
    float ydistance = _path[idx].y - _y;   

    return sf::Vector2f(xdistance, ydistance);
}