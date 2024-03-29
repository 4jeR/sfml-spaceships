#pragma once
#include "state.h"

class PauseState : public State{
public:
    PauseState(std::array<State*, 5>& states, sf::RenderWindow* window);

    ~PauseState();

    void Render() noexcept override;

    void UpdateState(std::array<State*, 5>& states,long unsigned int& current_state) noexcept override;
    
    std::pair<sf::RectangleShape*, sf::RectangleShape*>& GetPause()noexcept;

    sf::Text* GetText()noexcept;

    sf::Font GetFont()noexcept;

    void RotateText(sf::Text* txt)noexcept;

    void InitState(std::array<State*, 5>& states)noexcept override;
private:
    std::pair<sf::RectangleShape*, sf::RectangleShape*> _pause;

    sf::Text* _text;

    sf::Text* _unpauseText;

    sf::Font _font;

    sf::SoundBuffer _sound_buffer;
    
    sf::Sound _sound;

    State* _gameptr;
};