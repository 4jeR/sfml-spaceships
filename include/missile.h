#pragma once
#include "object.h"

class Missile: public Object{
public:
    Missile(float x, float y, sf::RenderWindow* winptr = nullptr);
    ~Missile();

    Missile& operator=(const Missile& rhs);

    void draw (sf::RenderTarget &target, sf::RenderStates states) const override;
private:
    
};