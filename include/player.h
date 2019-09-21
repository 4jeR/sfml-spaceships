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
    void UpdateTransforms()noexcept override;
    void Rotate(float angle)noexcept override;
    void Accelerate(float value)noexcept;
    void Update() noexcept override;
    sf::Shape* GetShape() noexcept override;
    sf::CircleShape* GetDot()noexcept;
    void InitWings()noexcept;
private:



    int _lives;
    int _cooldown;
    float _radius;
    Missile* _missile;
    sf::CircleShape* _shape;
    sf::CircleShape* _dot;
};