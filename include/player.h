#pragma once
#include "object.h"
#include "missile.h"

class Player : public Object{
public:
    Player(float x, float y,sf::RenderWindow* window = nullptr,  float radius = 22.0f, int foreign = 1);
    ~Player();
    static Player* InstantiatePlayer(float x, float y, sf::RenderWindow* window = nullptr, float radius = 22.0f, int foreign = 1);
    Player& operator=(const Player& rhs);

    int Cooldown()const noexcept;
    int& GetCooldown() noexcept;

    int Lives()const noexcept;
    int& GetLives()noexcept;

    
    int Score()const noexcept;
    int& GetScore()noexcept;


    Missile* Shoot()noexcept;
    void UpdateAll() noexcept override;
    sf::Shape* GetShape() noexcept override;
    sf::CircleShape* GetDot()noexcept;
    bool OnCollide(Object* other)noexcept override;
    void AddScore(int value)noexcept;
private:
    void Move()noexcept;
    void InitWings()noexcept;
    void UpdateTransforms()noexcept override;
    void Rotate()noexcept override;
    void Accelerate()noexcept;



    int _cooldown;
    int _lives;
    Missile* _missile;
    sf::CircleShape* _shape;
    sf::CircleShape* _dot;
    int _score;

    sf::SoundBuffer _sound_buffer;
    sf::Sound _sound;
};