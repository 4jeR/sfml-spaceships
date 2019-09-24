#include "button.h"

Button::Button(float x, float y, sf::String string){
    _shape = new sf::RectangleShape(sf::Vector2f(x , y));

    _shape ->setSize(sf::Vector2f(270, 50));
    _shape ->setFillColor(sf::Color::Transparent);
    _shape ->setOutlineColor(sf::Color::Yellow);
    _shape ->setOutlineThickness(2.0f);
    _shape->setPosition(x , y);

    if(!_font.loadFromFile("../fonts/leders st.ttf")){
    }
    _text = new sf::Text(string,_font, 20);
    _text ->setFont(_font);
    _text ->setPosition(x + 25, y + 15);
    _text->setFillColor(sf::Color::Red);
}

Button::~Button(){
    delete _shape;
    delete _text;
}


sf::RectangleShape* Button::GetShape()noexcept{
    return _shape;
}

sf::Text* Button::GetText()noexcept{
    return _text;
}

sf::Font Button::GetFont()noexcept{
    return _font;
}
