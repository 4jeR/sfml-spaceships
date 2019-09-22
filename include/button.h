#pragma once
#include "sfml_headers.h"

class Button{
public:
    Button(int x, int y);

    sf::RectangleShape& GetShape()noexcept;
    sf::Font& GetFont()noexcept;
    sf::Text& GetText()noexcept;
private:
    sf::RectangleShape _shape;
    sf::Font _font;
    sf::Text _text;
};