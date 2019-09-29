#include "object.h"


Object::Object(float x, float y, sf::RenderWindow* winptr, float radius, int foreign)
:_x(x), _y(y),_window(winptr),_radius(radius),_currentSpeed(0.0f),_isDestroyed(false),_foreign(foreign)
{
    // std::cout << __PRETTY_FUNCTION__ << std::endl;
    if(!_sb_destroy.loadFromFile("../audio/destroy.wav")){

    }
    _sound_destroy.setBuffer(_sb_destroy);
    _sound_destroy.setVolume(40);
}

Object::~Object(){

}

bool Object::operator==(const Object& rhs)const noexcept{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
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

sf::RenderWindow* Object::Window()noexcept{
    return _window;
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


std::string Object::Name()const noexcept{
    return _name;
}

float Object::Radius()const noexcept{
    return _radius;
}

float& Object::GetRadius() noexcept{
    return _radius;
}

int Object::Foreign()const noexcept{
    return _foreign;
}

int& Object::GetForeign() noexcept{
    return _foreign;
}


bool Object::DisappearedFromWindow()noexcept{
    float xx = static_cast<float>(_window->getSize().x);
    float yy = static_cast<float>(_window->getSize().y);
    if(!((0 < _x && _x < xx) && (0 < _y && _y < yy))){
        _isDestroyed = true;
    }
    return _isDestroyed;
}


bool Object::OnCollide(Object* other)noexcept{
    if(this->_foreign != other ->_foreign){
        float dx = this->_x - other->_x;
        float dy = this->_y - other->_y;
        float distance = std::sqrt(dx*dx + dy*dy);
        if(distance <= 15.5f){
            std::cout << "collision detected! between "<<  _name << " and " << other->Name() << std::endl;
            this->GetDestroyState() = true;
            other->GetDestroyState() = true;
            return true;
        }
    }
    return false;
}


float Object::CalcAngularVelocity(float current_speed)const noexcept{
    float abs_speed = std::abs(current_speed);
    if(abs_speed <= 200.0f){
        return 0.002f * std::sqrt(abs_speed / 3.0f);
    }
    else if(200.0f < abs_speed&& abs_speed <= 600.0f){
        return 0.001f * std::sqrt(2.0f * abs_speed / 3.0f);
    }
    else if(600.0f < abs_speed){
        return 0.007f * std::sqrt(4.0f * abs_speed / 3.0f);
    }
    else return 0.0f;
}

float Object::CalcAcceleration(float current_speed, bool add)const noexcept{
    float value = 0.0f;
    if(add){
        if(current_speed <= 200.0f){
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

void Object::SetForeign(int value)noexcept{
    _foreign = value;
}