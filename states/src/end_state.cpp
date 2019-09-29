#include "end_state.h"

EndState::EndState(std::array<State*, 5>& states, sf::RenderWindow* window)
:State(window)
{
    _gameptr = states[4];
    InitState(states);
}

EndState::~EndState(){
    delete _text;
}

void EndState::Render() noexcept{
    _window -> draw(*_text);
}

void EndState::UpdateState([[maybe_unused]] std::array<State*, 5>& states, [[maybe_unused]] long unsigned int& current_state) noexcept{
    Render();
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return)){
        _window->close();
    }
}


sf::Text* EndState::GetText()noexcept{
    return _text;
}

sf::Font EndState::GetFont()noexcept{
    return _font;
}

void EndState::InitState([[maybe_unused]] std::array<State*, 5>& states)noexcept{
    if(!_font.loadFromFile("../fonts/leders st.ttf")){
    }

    
    float xx = static_cast<float>(_window->getSize().x) / 2.0f;
    float yy = static_cast<float>(_window->getSize().y) / 2.0f;
    

    _text = new sf::Text("Game over!",_font, 45);
    _text ->setPosition(xx - 200.0f, yy - 120.0f);
    _text ->setFont(_font);
    _text->setFillColor(sf::Color::Red);
    
}
