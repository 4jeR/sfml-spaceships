#pragma once
#include "object.h"

class Missile: public Object{
public:
    Missile(float x, float y, sf::RenderWindow* winptr = nullptr);
    ~Missile();
    
    static Missile* InstantiateMissile(float x, float y, sf::RenderWindow* window);
    
    Missile& operator=(const Missile& rhs);

    void MoveInX(float value)noexcept override;
    void MoveInY(float value)noexcept override;
    void Draw(const sf::Drawable& obj)const override;
    void Update() noexcept override;
    sf::Shape* GetShape() override;
private:
    sf::RectangleShape* _shape; 
};