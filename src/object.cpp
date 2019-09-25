#include "object.h"


Object::Object(float x, float y, sf::RenderWindow* winptr, float radius)
:_x(x), _y(y),_window(winptr),_radius(radius),_currentSpeed(0.0f),_isDestroyed(false)
{
    // std::cout << __PRETTY_FUNCTION__ << std::endl;
    if(!_sb_destroy.loadFromFile("../audio/destroy.wav")){

    }
    _sound_destroy.setBuffer(_sb_destroy);
    _sound_destroy.setVolume(40);
}

Object::~Object(){
    // std::cout << __PRETTY_FUNCTION__ << std::endl;
}

bool Object::operator==(const Object& rhs)const noexcept{
    return this == &rhs;
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

bool Object::IsDestroyed()const noexcept{
    return _isDestroyed;
}

bool& Object::GetDestroyState()noexcept{
    return _isDestroyed;
}

float Object::CurrentSpeed()const noexcept{
    return _currentSpeed;
}

float& Object::GetCurrentSpeed()noexcept{
    return _currentSpeed;
}

sf::Sound& Object::Sound()noexcept{
    return _sound_destroy;
}

bool Object::DisappearedFromWindow()noexcept{
    float xx = static_cast<float>(_window->getSize().x);
    float yy = static_cast<float>(_window->getSize().y);
    if(!((0 < _x && _x < xx) && (0 < _y && _y < yy))){
        _isDestroyed = true;
    }
    return _isDestroyed;
}


void Object::OnCollide(Object* other)noexcept{
    if(_x == other->_x && _y == other->_y){
        std::cout << "collision detected!" << std::endl;
        delete this;
        delete other;
    }
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