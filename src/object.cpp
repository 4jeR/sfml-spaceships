#include "object.h"


Object::Object(float x, float y, sf::RenderWindow* winptr)
:_x(x), _y(y),_window(winptr),_currentSpeed(0.0f)
{

}

Object::~Object(){
    
}

Object& Object::operator=(const Object& rhs){
    _x = rhs._x;
    _y = rhs._y;
    _window = rhs._window;

    return *this;
}

float Object::CurrentSpeed()const noexcept{
    return _currentSpeed;
}

float& Object::GetCurrentSpeed()noexcept{
    return _currentSpeed;
}

float Object::X()const noexcept{
    return _x;
}

float& Object::GetX()noexcept{
    return _x;
}

float Object::Y()const noexcept{
    return _y;
}

float& Object::GetY()noexcept{
    return _y;
}


float Object::CalcAngularVelocity(float current_speed)const noexcept{
    float value = 0.0f;
    if(0.0f <= current_speed && current_speed <= 200.0f){
        value =  0.002f * std::sqrt(current_speed / 3.0f);
    }
    else if(200.0f < current_speed && current_speed <= 600.0f){
        value  = 0.001f * std::sqrt(2.0f * current_speed / 3.0f);
    }
    else if(600.0f < current_speed && current_speed <= 895.0f){
        value  = 0.007f * std::sqrt(4.0f * current_speed / 3.0f);
    }

    return value ;
    //(current_speed >= 0.0f) ? 0.005f * std::sqrt(6.0f * current_speed) : 0.0f;
}

float Object::CalcAcceleration(float current_speed, bool add)const noexcept{
    float value = 0.0f;
    if(add){
        if(0.0f <= current_speed && current_speed <= 200.0f){
            value = 1.5f;
        }
        else if(200.0f < current_speed && current_speed <= 600.0f){
            value  = 2.0f;
        }
        else if(600.0f < current_speed && current_speed <= 894.5f){
            value  = 0.5f;
        }
    }
    else if(!add){
        if(1.0f <= current_speed && current_speed <= 200.0f){
            value = -1.0f;
        }
        else if(200.0f <= current_speed){
            value = -3.0f;
        }
    }
    return value;
}