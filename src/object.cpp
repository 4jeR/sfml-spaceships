#include "object.h"


Object::Object(float x, float y, sf::RenderWindow* winptr)
:_x(x), _y(y),_window(winptr),_currentSpeed(0.0f)
{

}

Object::~Object(){
    
}

Object& Object::operator=(const Object& rhs){
    _x = rhs._x;
    _y = rhs._y;
    _window = rhs._window;

    return *this;
}

float Object::CurrentSpeed()const noexcept{
    return _currentSpeed;
}

float& Object::GetCurrentSpeed()noexcept{
    return _currentSpeed;
}

float Object::X()const noexcept{
    return _x;
}

float& Object::GetX()noexcept{
    return _x;
}

float Object::Y()const noexcept{
    return _y;
}

float& Object::GetY()noexcept{
    return _y;
}
