#pragma once
#include "object.h"


class Enemy : public Object{
public:
    Enemy(float x, float y, sf::RenderWindow* winptr = nullptr, float radius = 12.0f);
    ~Enemy();

    static Enemy* InstantiateEnemy(float x, float y, sf::RenderWindow* winptr = nullptr, float radius = 12.0f);



    void UpdateAll() noexcept override;
    sf::Shape* GetShape() noexcept override;
private:    
    void UpdateTransforms()noexcept override;
    void Rotate()noexcept override;

    sf::CircleShape* _shape;
    float _radius;

    
};