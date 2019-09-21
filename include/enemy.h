#pragma once
#include "object.h"


class Enemy : public Object{
public:
    Enemy(float x, float y, sf::RenderWindow* winptr = nullptr);
    ~Enemy();
    
    float CurrentSpeed()const noexcept;
    float& GetCurrentSpeed()noexcept;
    float X()const noexcept;
    float& GetX()noexcept;
    float Y()const noexcept;
    float& GetY()noexcept;


    virtual void UpdateAll() noexcept override;
    virtual sf::Shape* GetShape() noexcept override;
private:    
    void UpdateTransforms()noexcept override;
    void Rotate()noexcept override;

    sf::CircleShape* _shape;
    float _radius;
};