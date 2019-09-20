#include "missile.h"


Missile::Missile(float x, float y, sf::RenderWindow* winptr)
:Object(x, y, winptr)
{
    std::cout << "Allocate memory for shape from Missile::Missile!" << std::endl;
    _shape = new sf::RectangleShape(sf::Vector2f(10.0f, 40.0f));
    _shape -> setPosition(x, y);
    _shape -> setOutlineColor(sf::Color::Red);
}

Missile* Missile::InstantiateMissile(float x, float y, sf::RenderWindow* window){
    std::cout << "Allocate memory for missile from Missile::InstantiateMissile" << std::endl;
    return new Missile(x, y, window);
}


Missile::~Missile(){
    delete _shape;
    std::cout << "Deleting missile from Missile class!" << std::endl;
}

void Missile::Draw(const sf::Drawable& obj)const{
    _window -> draw(obj);
}



Missile& Missile::operator=(const Missile& rhs){
    Object::operator=(rhs);

    return *this;
}

sf::Shape* Missile::GetShape(){
    return _shape;
}

