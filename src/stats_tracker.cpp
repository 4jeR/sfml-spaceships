#include "stats_tracker.h"

StatsTracker::StatsTracker(){
    if(!_font.loadFromFile("../fonts/Arcade.ttf")){
    }

    _lives_text = new sf::Text;
    _lives_text ->setPosition(10.0f, 5.0f);
    _lives_text ->setFont(_font);
    _lives_text ->setCharacterSize(30);
    _lives_text->setFillColor(sf::Color::Yellow);

    _score_text = new sf::Text;
    _score_text ->setPosition(1000.0f, 5.0f);
    _score_text ->setFont(_font);
    _score_text ->setCharacterSize(30);
    _score_text->setFillColor(sf::Color::Yellow);

}

StatsTracker::~StatsTracker(){
    delete _lives_text;
    delete _score_text;
}

sf::Text* StatsTracker::LivesText()noexcept{
    return _lives_text;
}


sf::Text* StatsTracker::ScoreText()noexcept{
    return _score_text;
}


void StatsTracker::UpdateStats(const Player* p)const noexcept{
    _lives_text->setString("LIVES:  " + std::to_string(p->Lives()));
    _score_text->setString("SCORE:  " + std::to_string(p->Score()));
}