#pragma once
#include "player.h"
#include <string>

class StatsTracker{
public:
    StatsTracker();
    ~StatsTracker();
    void ShowStats(const Player* p, sf::RenderWindow* window)noexcept;
private:
    sf::Text* _lives_text;
    sf::Font _font;
};