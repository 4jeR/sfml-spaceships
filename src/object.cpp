#include "object.h"


Object::Object(float x, float y, sf::RenderWindow* winptr)
:_x(x), _y(y),_window(winptr)
{

}

Object::~Object(){
    delete _window;
}

