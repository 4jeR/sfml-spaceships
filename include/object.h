#pragma once
#include "sfml_headers.h"
#include <iostream>
#include <cmath>
#include <array>

class Object{
public:
    Object(float x, float y, sf::RenderWindow* winptr = nullptr);
    virtual ~Object();

    Object& operator=(const Object& rhs);
    
    float CurrentSpeed()const noexcept;
    float& GetCurrentSpeed()noexcept;
    float X()const noexcept;
    float& GetX()noexcept;
    float Y()const noexcept;
    float& GetY()noexcept;
    
    virtual void UpdateAll() noexcept = 0;
    virtual sf::Shape* GetShape() noexcept = 0;
    float CalcAngularVelocity(float current_speed)const noexcept;
    float CalcAcceleration(float current_speed, bool add)const noexcept;
protected:
    virtual void UpdateTransforms()noexcept = 0;
    virtual void Rotate()noexcept = 0;
    float _x;
    float _y;
    sf::RenderWindow* _window;
    float _currentSpeed;
};