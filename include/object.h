#pragma once
#include "sfml_headers.h"
#include <iostream>
#include <cmath>
#include <array>

class Object{
public:
    Object(float x, float y, sf::RenderWindow* winptr , float radius );
    virtual ~Object();

    bool operator==(const Object& rhs)const noexcept;
    
    float X()const noexcept;
    float& GetX()noexcept;
    float Y()const noexcept;
    float& GetY()noexcept;
    float CurrentSpeed()const noexcept;
    float& GetCurrentSpeed()noexcept;
    bool IsDestroyed()const noexcept;
    bool& GetDestroyState()noexcept;
    
    virtual void UpdateAll() noexcept = 0;
    virtual sf::Shape* GetShape() noexcept = 0;
    float CalcAngularVelocity(float current_speed)const noexcept;
    float CalcAcceleration(float current_speed, bool add)const noexcept;
    virtual void OnCollide(Object* other)noexcept;
    sf::Sound& Sound()noexcept;
protected:
    virtual void UpdateTransforms()noexcept = 0;
    virtual void Rotate()noexcept = 0;
    bool DisappearedFromWindow()noexcept;
    float _x;
    float _y;
    sf::RenderWindow* _window;
    float _radius;
    float _currentSpeed;
    bool _isDestroyed;

    sf::SoundBuffer _sb_destroy;
    sf::Sound _sound_destroy;
};