#include "stats_tracker.h"

StatsTracker::StatsTracker(){
    if(!_font.loadFromFile("../fonts/leders st.ttf")){
    }

    _lives_text = new sf::Text;
    _lives_text ->setPosition(10.0f, 5.0f);
    _lives_text ->setFont(_font);
    _lives_text ->setCharacterSize(20);
    _lives_text->setFillColor(sf::Color::Yellow);

}

StatsTracker::~StatsTracker(){
    delete _lives_text;
}

sf::Text* StatsTracker::Text()noexcept{
    return _lives_text;
}


void StatsTracker::UpdateStats(const Player* p)const noexcept{
    _lives_text->setString(std::string("   LIVES" + p->Lives()));
    
}