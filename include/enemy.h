#pragma once
#include "object.h"
#include "missile.h"
#include "player.h"

class Enemy : public Object{
public:
    Enemy(float x, float y, sf::RenderWindow* winptr = nullptr, float radius = 11.0f, int foreign = 2);

    ~Enemy();

    void UpdateAll() noexcept override;

    static Enemy* InstantiateEnemy(float x, float y, sf::RenderWindow* winptr = nullptr, float radius = 11.0f, int foreign = 2);
    
    sf::Shape* GetShape() noexcept override;

    Missile* Shoot()noexcept;
private:    
    void UpdateTransforms()noexcept override;

    void Rotate()noexcept override;

    void Patrol()noexcept;

    sf::Vector2f CalcDistanceTo(int idx)const noexcept;

    sf::CircleShape* _shape;

    float _radius;  
    
    Missile* _missile;

    sf::SoundBuffer _sound_buffer;
    sf::Sound _sound;
    sf::Vector2f _path[4];
    int _currentPath;
};