#include "player.h"



Player::Player(float x, float y, sf::RenderWindow* winptr)
:Object(x, y, winptr),_cooldown(0),_lives(3),_radius(22.0f)
{   
    

    _shape = new sf::CircleShape(_radius, 3);
    _shape -> setPosition(_x, _y);
    _shape -> setFillColor(sf::Color::Transparent);
    _shape -> setOutlineThickness(1.5f);
    _shape -> setOutlineColor(sf::Color::Green);
    _shape -> setOrigin(static_cast<float>(static_cast<double>(_radius) * std::sqrt(3)/ 2.0), _radius );

    _dot = new sf::CircleShape(_radius / 7.0f);
    _dot -> setPosition(_x, _y);
    _dot -> setFillColor(sf::Color::Green);
    

}


Player::~Player(){
    delete _shape;
    delete _dot;
}


Missile* Player::Shot()noexcept{
    /**
     * TODO: 
     *      audio playing when shooting new missile
    */
    _missile = new Missile(_x, _y, _window);
    float byX =  1.5f * _radius * static_cast<float>(std::sin(static_cast<double>(_shape->getRotation()) * M_PI / 180.0));
    float byY = -1.5f * _radius * static_cast<float>(std::cos(static_cast<double>(_shape->getRotation()) * M_PI / 180.0));
    _missile -> GetShape() -> move(byX, byY );
    _missile -> GetShape() -> rotate(_shape -> getRotation());
    return _missile;
}

Player* Player::InstantiatePlayer(float x, float y, sf::RenderWindow* window){
    return new Player(x, y, window);
}




Player& Player::operator=(const Player& rhs){
    Object::operator=(rhs);
    _lives = rhs._lives;
    
    return *this;
}



sf::Shape* Player::GetShape()noexcept{
    return _shape;
}

sf::CircleShape* Player::GetDot()noexcept{
    return _dot;
}

int& Player::GetLives()noexcept{
    return _lives;
}

int& Player::GetCooldown() noexcept{
    return _cooldown;
}

int Player::Cooldown()const noexcept{
    return _cooldown;
}

int Player::Lives()const noexcept{
    return _lives;
}

float Player::Radius()const noexcept{
    return _radius;
}

float& Player::GetRadius() noexcept{
    return _radius;
}

void Player::UpdateAll() noexcept{
   UpdateTransforms();
   ++_cooldown;
   // and more stuff later on ...
}


void Player::UpdateTransforms()noexcept {
    Accelerate();
    Rotate();
}

void Player::Accelerate()noexcept{
    Move();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
        if(_currentSpeed < 550.0f)
            _currentSpeed += 1.5f;      // <-- THIS IS REAL ACCELERATION RATE
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
        if(_currentSpeed > 0.0f)
            _currentSpeed -= 2.0f;      // <-- THIS IS REAL DECCELERATION RATE
    }
}

void Player::Move() noexcept{
    float byX = 0.001f * _currentSpeed *  static_cast<float>(std::sin(static_cast<double>(_shape->getRotation()) * M_PI / 180.0));
    float byY = -0.001f * _currentSpeed *  static_cast<float>(std::cos(static_cast<double>(_shape->getRotation()) * M_PI / 180.0));
        
    GetShape() -> move(byX, byY );
    GetDot()   -> move(byX, byY );
    GetX() += byX;
    GetY() += byY;
}


void Player::Rotate()noexcept {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
        float rotateCoef = -0.38f;
        _shape -> rotate(rotateCoef);
        _dot -> rotate(rotateCoef);
    } 
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
        float rotateCoef = 0.38f;
        _shape -> rotate(rotateCoef);
        _dot -> rotate(rotateCoef);
    }
}