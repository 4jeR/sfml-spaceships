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
   
    virtual void Update() noexcept = 0;
    virtual void Rotate(float angle)noexcept = 0;
    virtual sf::Shape* GetShape() noexcept = 0;
protected:
    virtual void UpdateTransforms()noexcept = 0;
    float _x;
    float _y;
    sf::RenderWindow* _window;
};