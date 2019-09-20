#pragma once
#include "object.h"
#include "missile.h"


class Player : public Object{
public:
    Player(float x, float y, sf::RenderWindow* winptr = nullptr);
    ~Player();
    static Player* InstantiatePlayer(float x, float y, sf::RenderWindow* window);
    Player& operator=(const Player& rhs);

    int& GetLives()noexcept;
    int& GetCooldown() noexcept;
    int Cooldown()const noexcept;
    int Lives()const noexcept;

    Missile* Shot()noexcept;
    void MoveInX(float value)noexcept override;
    void MoveInY(float value)noexcept override;
    void Draw(const sf::Drawable& obj)const override;
    void Update() noexcept override;
    sf::Shape* GetShape() override;
private:

    int _lives;
    int _cooldown;
    Missile* _missile;
    sf::CircleShape* _shape;
};