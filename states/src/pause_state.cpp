#include "pause_state.h"


PauseState::PauseState(std::array<State*, 3>& states, sf::RenderWindow* window)
:State(window)
{
    InitState(states);
}


PauseState::~PauseState(){
    delete _pause.first;
    delete _pause.second;
    delete _text;
    delete _unpauseText;
}


void PauseState::Render() noexcept {
    _window -> draw(*_pause.first);
    _window -> draw(*_pause.second);
    _window -> draw(*_text);
    _window -> draw(*_unpauseText);
}


void PauseState::UpdateState(std::array<State*, 3>& states,long unsigned int& current_state) noexcept {
    Render();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return)){
        current_state = 1;
    }
}


void PauseState::InitState([[maybe_unused]] std::array<State*, 3>& states)noexcept {
    std::cout << "entering pause state!"<<std::endl;
    std::cout << "states stack size -> " << states.size() << std::endl;

    if(!_font.loadFromFile("../fonts/leders st.ttf")){
    }
    float xx = static_cast<float>(_window->getSize().x) / 2.0f;
    float yy = static_cast<float>(_window->getSize().y) / 2.0f;
    _pause.first = new sf::RectangleShape(sf::Vector2f(xx, yy));
    _pause.second = new sf::RectangleShape(sf::Vector2f(xx + 40.0f, yy));


    _pause.first ->setSize(sf::Vector2f(20, 100));
    _pause.first ->setFillColor(sf::Color::Yellow);
    _pause.first ->setOutlineColor(sf::Color(245, 150, 10));
    _pause.first ->setOutlineThickness(2.0f);
    _pause.first ->setPosition(xx - 25.0f, yy - 30.0f);

    _pause.second ->setSize(sf::Vector2f(20, 100));
    _pause.second ->setFillColor(sf::Color::Yellow);
    _pause.second ->setOutlineColor(sf::Color(245, 150, 10));
    _pause.second ->setOutlineThickness(2.0f);
    _pause.second ->setPosition(xx + 25.0f, yy - 30.0f);
    
    _text = new sf::Text("PAUSE",_font, 45);
    _text ->setPosition(xx - 100.0f, yy - 150.0f);
    _text ->setFont(_font);
    _text->setFillColor(sf::Color::Red);

    _unpauseText = new sf::Text("to unpause press [enter]", _font, 15);
    _unpauseText ->setPosition(xx - 150.0f, yy + 150.0f);
    _unpauseText ->setFont(_font);
    _unpauseText->setFillColor(sf::Color::Red);
}



std::pair<sf::RectangleShape*, sf::RectangleShape*>& PauseState::GetPause()noexcept{
    return _pause;
}

sf::Text* PauseState::GetText()noexcept{
    return _text;
}


sf::Font PauseState::GetFont()noexcept{
    return _font;
}




