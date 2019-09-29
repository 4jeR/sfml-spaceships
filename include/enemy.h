#pragma once
#include "object.h"
#include "missile.h"

class Enemy : public Object{
public:
    Enemy(float x, float y, sf::RenderWindow* winptr = nullptr, float radius = 11.0f, int foreign = 2);
    ~Enemy();

    static Enemy* InstantiateEnemy(float x, float y, sf::RenderWindow* winptr = nullptr, float radius = 11.0f, int foreign = 2);



    void UpdateAll() noexcept override;
    sf::Shape* GetShape() noexcept override;
private:    
    void UpdateTransforms()noexcept override;
    void Rotate()noexcept override;

    sf::CircleShape* _shape;
    float _radius;  
};