#include "missile.h"


Missile::Missile(float x, float y, sf::RenderWindow* winptr)
:Object(x, y, winptr)
{
    _shape = new sf::RectangleShape(sf::Vector2f(2.0f, 8.0f));
    _shape -> setPosition(_x, _y);
    _shape -> setOutlineColor(sf::Color::Red);
    _shape -> setOutlineThickness(1.0f);
    _shape -> setFillColor(sf::Color::Transparent);
    _currentSpeed = 1500.0f;
}

Missile* Missile::InstantiateMissile(float x, float y, sf::RenderWindow* window){
    return new Missile(x, y, window);
}


Missile::~Missile(){
    delete _shape;
}




Missile& Missile::operator=(const Missile& rhs){
    Object::operator=(rhs);

    return *this;
}

sf::Shape* Missile::GetShape()noexcept{
    return _shape;
}

void Missile::UpdateAll() noexcept {
    UpdateTransforms();
    DisappearedFromWindow();
}

void Missile::UpdateTransforms()noexcept {
    Rotate();
    float byX = 0.001f * _currentSpeed *  static_cast<float>(std::sin(static_cast<double>(_shape->getRotation()) * M_PI / 180.0));
    float byY = -0.001f * _currentSpeed *  static_cast<float>(std::cos(static_cast<double>(_shape->getRotation()) * M_PI / 180.0));
       
    _shape -> move(byX, byY );
    _x += byX;
    _y += byY;
}

void Missile::Rotate()noexcept{
    // when hits another object...
}
