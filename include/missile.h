#pragma once
#include "object.h"

class Missile: public Object{
public:
    Missile(float x, float y, sf::RenderWindow* winptr = nullptr);
    ~Missile();

    Missile& operator=(const Missile& rhs);
    void Draw(const sf::Drawable& obj)const override;
    
private:
    sf::RectangleShape* _shape; 
};