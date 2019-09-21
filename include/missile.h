#pragma once
#include "object.h"

class Missile: public Object{
public:
    Missile(float x, float y, sf::RenderWindow* winptr = nullptr);
    ~Missile();
    
    static Missile* InstantiateMissile(float x, float y, sf::RenderWindow* window);
    
    Missile& operator=(const Missile& rhs);
    void UpdateTransforms()noexcept override;
    void Rotate(float angle)noexcept override;

    void Update() noexcept override;
    sf::Shape* GetShape() noexcept override;
private:
    sf::RectangleShape* _shape; 
};