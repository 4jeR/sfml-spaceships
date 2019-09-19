#pragma once
#include "sfml_headers.h"

class Object : public sf::Drawable {
public:
    Object(float x, float y, sf::RenderWindow* winptr = nullptr);
    virtual ~Object();
protected:
    
    float _x;
    float _y;
    sf::RenderWindow* _window;
};