#pragma once
#include "sfml_headers.h"



class Player{
public:
    Player(float x, float y, sf::RenderWindow* = nullptr);
    ~Player();
    static Player* InstantiatePlayer(float x, float y, sf::RenderWindow* window);
    
    void Shot()noexcept;
    void MoveInX(float value)noexcept;
    void MoveInY(float value)noexcept;
private:
    float _x;
    float _y;

    int _lives;
    sf::RenderWindow* _window;

};