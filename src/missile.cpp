#include "missile.h"


Missile::Missile(float x, float y, sf::RenderWindow* winptr)
:Object(x, y, winptr)
{

}


Missile::~Missile(){
    delete _shape;
}

void Missile::Draw(const sf::Drawable& obj)const{
    _window -> draw(obj);
}



Missile& Missile::operator=(const Missile& rhs){
    Object::operator=(rhs);

    return *this;
}

