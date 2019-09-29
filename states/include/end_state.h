#pragma once
#include "state.h"
#include <time.h>
#include "game_state.h"

class EndState : public State{
public:
    EndState(std::array<State*, 5>& states, sf::RenderWindow* window);
    ~EndState();
    void Render() noexcept override;
    void UpdateState(std::array<State*, 5>& states,long unsigned int& current_state) noexcept override;

    sf::Text* GetText()noexcept;
    sf::Font GetFont()noexcept;
    void InitState(std::array<State*, 5>& states)noexcept override;
private:
    sf::Text* _text; 
    sf::Text* _scoretext;   
    sf::Font _font;
    
    State* _gameptr;
};