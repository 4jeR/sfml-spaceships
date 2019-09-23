#pragma once
#include "sfml_headers.h"
#include <iostream>

class Button{
public:
    Button(float x, float y, sf::String string);
    ~Button();
    sf::RectangleShape*& GetShape()noexcept;
    sf::Text* GetText()noexcept;
    sf::Font GetFont()noexcept;
private:
    sf::RectangleShape* _shape;
    sf::Text* _text;

    sf::Font _font;
};