#include "object.h"


Object::Object(float x, float y, sf::RenderWindow* winptr)
:_x(x), _y(y),_window(winptr)
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
