#pragma once
#include "player.h"
#include <string>

class StatsTracker{
public:
    StatsTracker();
    ~StatsTracker();
    void UpdateStats(const Player* p)const noexcept;
    sf::Text* Text()noexcept;
private:
    sf::Text* _lives_text;
    sf::Font _font;
};