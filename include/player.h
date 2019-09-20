#pragma once
#include "object.h"
#include "missile.h"


class Player : public Object{
public:
    Player(float x, float y, sf::RenderWindow* winptr = nullptr);
    ~Player();
    static Player* InstantiatePlayer(float x, float y, sf::RenderWindow* window);
    Player& operator=(const Player& rhs);

    void Shot()noexcept;
    void MoveInX(float value)noexcept;
    void MoveInY(float value)noexcept;
    void Draw(const sf::Drawable& obj)const override;
    sf::Shape* GetShape() override;
private:

    int _lives;
    
    Missile* _missile;
    sf::CircleShape* _shape;
};