#pragma once
#include "player.h"
#include <string>

class StatsTracker{
public:
    StatsTracker();

    ~StatsTracker();

    void UpdateStats(const Player* p)const noexcept;

    sf::Text* LivesText()noexcept;

    sf::Text* ScoreText()noexcept;
private:
    sf::Text* _lives_text;

    sf::Text* _score_text;
    
    sf::Font _font;
};