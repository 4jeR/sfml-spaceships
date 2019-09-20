#pragma once
#include "sfml_headers.h"
#include <iostream>
#include <cmath>

class Object{
public:
    Object(float x, float y, sf::RenderWindow* winptr = nullptr);
    virtual ~Object();

    Object& operator=(const Object& rhs);
    
    virtual void MoveInX(float value)noexcept = 0;
    virtual void MoveInY(float value)noexcept = 0;
    virtual void Draw(const sf::Drawable& obj)const = 0;
    virtual void Update() noexcept = 0;
    virtual sf::Shape* GetShape() = 0;
protected:
    float _x;
    float _y;
    sf::RenderWindow* _window;
    float _angle;
};