#pragma once
#include "object.h"


class Missile: public Object{
public:
    Missile(float x, float y, sf::RenderWindow* winptr = nullptr, float radius = 3.0f);
    ~Missile();
    
    static Missile* InstantiateMissile(float x, float y, sf::RenderWindow* winptr = nullptr, float radius = 3.0f);
    
    Missile& operator=(const Missile& rhs);
    
    void UpdateAll() noexcept override;
    sf::Shape* GetShape() noexcept override;
private:
    void UpdateTransforms()noexcept override;
    void Rotate()noexcept override;


    sf::RectangleShape* _shape; 
};