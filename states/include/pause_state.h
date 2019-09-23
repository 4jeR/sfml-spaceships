#pragma once
#include "state.h"

class PauseState : public State{
public:
    PauseState(std::stack<State*>& states, sf::RenderWindow* window);
    ~PauseState();
    void Render() noexcept override;
    void UpdateState(std::stack<State*>& states, sf::RenderWindow* window) noexcept override;
    
    std::pair<sf::RectangleShape*, sf::RectangleShape*>& GetPause()noexcept;
    sf::Text* GetText()noexcept;
    sf::Font GetFont()noexcept;

private:
    void InitState([[maybe_unused]] std::stack<State*>& states,[[maybe_unused]] sf::RenderWindow* window)noexcept override;

    std::pair<sf::RectangleShape*, sf::RectangleShape*> _pause;
    sf::Text* _text;
    sf::Text* _unpauseText;
    sf::Font _font;

};