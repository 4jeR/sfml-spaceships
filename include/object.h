#pragma once
#include "sfml_headers.h"

class Object{
public:
    Object(float x, float y, sf::RenderWindow* winptr = nullptr);
    Object& operator=(const Object& rhs);
    virtual ~Object();
    virtual void Draw(const sf::Drawable& obj)const = 0;
    virtual sf::Shape* GetShape() = 0;
protected:
    float _x;
    float _y;
    sf::RenderWindow* _window;
};