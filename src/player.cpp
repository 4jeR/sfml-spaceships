#include "player.h"



Player::Player(float x, float y, sf::RenderWindow* winptr)
:Object(x, y, winptr),_cooldown(0),_radius(36.0f)
{   
    

    _shape = new sf::CircleShape(_radius, 3);
    std::cout << "Allocate memory for shape from Player::Player!" << std::endl;
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
    std::cout << "Deleting shape from Playerclass!" << std::endl;
}


Missile* Player::Shot()noexcept{
    std::cout << "SINUS 90: " << std::sin(M_PI*90 / 180) << std::endl;
    /**
     * TODO: 
     *      audio playing when shooting new missile
    */
    _missile = new Missile(_x + 5.0f, _y, _window);
    float byX =  1.5f * _radius * static_cast<float>(std::sin(static_cast<double>(_shape->getRotation()) * M_PI / 180.0));
    float byY = -1.5f * _radius * static_cast<float>(std::cos(static_cast<double>(_shape->getRotation()) * M_PI / 180.0));
    _missile -> GetShape() -> move(byX, byY );
    _missile -> GetShape() -> rotate(_shape -> getRotation());
    return _missile;
}

Player* Player::InstantiatePlayer(float x, float y, sf::RenderWindow* window){
    std::cout << "Allocate memory for Player from Player:InstantiatePlayer!" << std::endl;
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

void Player::Update() noexcept{
   
}


void Player::UpdateTransforms()noexcept {

}

void Player::Accelerate(float value)noexcept{
    float accCoef = 0.000008f;
    float byX = accCoef * value * _radius * static_cast<float>(std::sin(static_cast<double>(_shape->getRotation()) * M_PI / 180.0));
    float byY = -accCoef * value * _radius * static_cast<float>(std::cos(static_cast<double>(_shape->getRotation()) * M_PI / 180.0));
    _shape -> move(byX, byY );
    _dot -> move(byX, byY );
    _x += byX;
    _y += byY;
}

void Player::Rotate(float angle)noexcept {
    float rotateCoef = -0.00036f;
    _shape -> rotate(rotateCoef * angle);
    _dot -> rotate(rotateCoef * angle);
    std::cout << "\n=======\nCurrent rotation: " << _shape->getRotation() << std::endl;
    std::cout << "Trangle origin: " << _shape->getOrigin().x << ", " << _shape->getOrigin().y << std::endl;
    std::cout << "dot origin: " << _dot->getOrigin().x << ", " << _dot->getOrigin().y << std::endl;
    std::cout << "\nTrangle position: :" <<  _shape->getPosition().x << ", " << _shape->getPosition().y << std::endl;
    std::cout << "bdot position: :" <<  _dot->getPosition().x << ", " << _dot->getPosition().y << std::endl;


}