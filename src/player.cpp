#include "player.h"



Player::Player(float x, float y, sf::RenderWindow* winptr, float radius, int foreign)
:Object(x, y, winptr, radius, foreign),_cooldown(0),_lives(3), _score(0)
{   
    
    // std::cout << __PRETTY_FUNCTION__ << std::endl;
    _shape = new sf::CircleShape(radius, 3);
    _shape -> setPosition(_x, _y);
    _shape -> setFillColor(sf::Color::Transparent);
    _shape -> setOutlineThickness(1.5f);
    _shape -> setOutlineColor(sf::Color::Green);
    _shape -> setOrigin(static_cast<float>(static_cast<double>(radius) * std::sqrt(3)/ 2.0), radius );

    _dot = new sf::CircleShape(radius / 7.0f);
    _dot -> setPosition(_x, _y);
    _dot -> setFillColor(sf::Color::Green);
    if(!_sound_buffer.loadFromFile("../audio/laser-shot.wav")){

    }
    _sound.setBuffer(_sound_buffer);
    _sound.setVolume(40);
    _name = "player";
}


Player::~Player(){
    // std::cout << __PRETTY_FUNCTION__ << std::endl;
    delete _shape;
    delete _dot;
}


Missile* Player::Shoot()noexcept{
    _sound.play();
    float byX =  1.5f * _radius * static_cast<float>(std::sin(static_cast<double>(_dot->getRotation()) * M_PI / 180.0));
    float byY = -1.5f * _radius * static_cast<float>(std::cos(static_cast<double>(_dot->getRotation()) * M_PI / 180.0));
    
    _currentSpeed -= 60.0f;
    
    _missile = new Missile(_x + byX, _y + byY, _window, _radius);
    _missile -> SetForeign(1);
    _missile -> GetShape() -> rotate(_dot -> getRotation());
    return _missile;
}

Player* Player::InstantiatePlayer(float x, float y, sf::RenderWindow* winptr,float radius, int foreign ){
    return new Player(x, y, winptr, radius, foreign);
}


void Player::AddScore(int value)noexcept{
    _score += value;
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




int& Player::GetScore()noexcept{
    return _score;
}
int Player::Score()const noexcept{
    return _score;
}


void Player::UpdateAll() noexcept{
   UpdateTransforms();
   DisappearedFromWindow();
   ++_cooldown;
   
   // and more stuff later on ...
}


void Player::UpdateTransforms()noexcept {
    Accelerate();
    Rotate();
}

void Player::Accelerate()noexcept{
    Move();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        _currentSpeed += CalcAcceleration(_currentSpeed, true);
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        _currentSpeed += CalcAcceleration(_currentSpeed, false);   
    
}

void Player::Move() noexcept{
    float byX =  0.001f * _currentSpeed *  static_cast<float>(std::sin(static_cast<double>(_shape->getRotation()) * M_PI / 180.0));
    float byY = -0.001f * _currentSpeed *  static_cast<float>(std::cos(static_cast<double>(_shape->getRotation()) * M_PI / 180.0));
        
    GetShape() -> move(byX, byY );
    GetDot()   -> move(byX, byY );
    GetX() += byX;
    GetY() += byY;
}

void Player::Rotate()noexcept {

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
        float rotateCoef = -(0.35f - CalcAngularVelocity(_currentSpeed));
        _shape -> rotate(rotateCoef);
        _dot -> rotate(rotateCoef);
    } 
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
        float rotateCoef =  0.35f - CalcAngularVelocity(_currentSpeed);
        _shape -> rotate(rotateCoef);
        _dot -> rotate(rotateCoef);
    }
}

bool Player::OnCollide(Object* other)noexcept{
    if(this->_foreign != other ->Foreign()){
        float dx = this->_x - other->X();
        float dy = this->_y - other->Y();
        float distance = std::sqrt(dx*dx + dy*dy);
        if(distance <= this->_radius + other->Radius()){
            --_lives;
            other->GetDestroyState() = true;
            return true;
        }
    }
    return false;
}

bool Player::DisappearedFromWindow()noexcept{
    float xx = static_cast<float>(_window->getSize().x);
    float yy = static_cast<float>(_window->getSize().y);
    if(!((0 < _x && _x < xx) && (0 < _y && _y < yy))){
        _isDestroyed = true;
        _lives = 0;
    }
    return _isDestroyed;
}