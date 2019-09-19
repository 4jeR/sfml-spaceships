#include "missile.h"


Missile::Missile(float x, float y, sf::RenderWindow* winptr)
:Object(x, y, winptr)
{

}


Missile::~Missile(){
}


void Missile::draw (sf::RenderTarget &target, sf::RenderStates states) const {
    
}


Missile& Missile::operator=(const Missile& rhs){
    Object::operator=(rhs);

    return *this;
}