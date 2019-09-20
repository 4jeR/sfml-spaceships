#pragma once
#include "object.h"

class Missile: public Object{
public:
    Missile(float x, float y, sf::RenderWindow* winptr = nullptr);
    ~Missile();
    static Missile* InstantiateMissile(float x, float y, sf::RenderWindow* window);
    Missile& operator=(const Missile& rhs);
    void Draw(const sf::Drawable& obj)const override;
    sf::Shape* GetShape() override;
private:
    sf::RectangleShape* _shape; 
};