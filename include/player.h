#pragma once
#include "object.h"
#include "missile.h"

class Player : public Object{
public:
    Player(float x, float y, sf::RenderWindow* winptr = nullptr);
    ~Player();
    static Player* InstantiatePlayer(float x, float y, sf::RenderWindow* window = nullptr);
    Player& operator=(const Player& rhs);

    int Cooldown()const noexcept;
    int& GetCooldown() noexcept;

    int Lives()const noexcept;
    int& GetLives()noexcept;

    float Radius()const noexcept;
    float& GetRadius()noexcept;
    
    int Score()const noexcept;
    int& GetScore()noexcept;


    Missile* Shot()noexcept;
    void UpdateAll() noexcept override;
    sf::Shape* GetShape() noexcept override;
    sf::CircleShape* GetDot()noexcept;

private:
    void Move()noexcept;
    void InitWings()noexcept;
    void UpdateTransforms()noexcept override;
    void Rotate()noexcept override;
    void Accelerate()noexcept;




    int _cooldown;
    int _lives;
    float _radius;
    Missile* _missile;
    sf::CircleShape* _shape;
    sf::CircleShape* _dot;
    int _score;
};