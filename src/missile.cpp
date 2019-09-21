#include "missile.h"


Missile::Missile(float x, float y, sf::RenderWindow* winptr)
:Object(x, y, winptr)
{
    std::cout << "Allocate memory for shape from Missile::Missile!" << std::endl;
    _shape = new sf::RectangleShape(sf::Vector2f(2.0f, 8.0f));
    _shape -> setPosition(x + 23.5f, y - 40.0f);
    _shape -> setOutlineColor(sf::Color::Red);
    _shape -> setOutlineThickness(1.0f);
    _shape -> setFillColor(sf::Color::Transparent);
}

Missile* Missile::InstantiateMissile(float x, float y, sf::RenderWindow* window){
    std::cout << "Allocate memory for missile from Missile::InstantiateMissile" << std::endl;
    return new Missile(x, y, window);
}


Missile::~Missile(){
    delete _shape;
    std::cout << "Deleting missile from Missile class!" << std::endl;
}




Missile& Missile::operator=(const Missile& rhs){
    Object::operator=(rhs);

    return *this;
}

sf::Shape* Missile::GetShape()noexcept{
    return _shape;
}

void Missile::Update() noexcept {
    /**
     * TODO: 
     *      update its position based on direction it was shot,
     *      and time passed 
    */
}

void Missile::UpdateTransforms()noexcept {

}

void Missile::Rotate(float angle)noexcept{

}