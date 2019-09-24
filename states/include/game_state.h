#pragma once
#include "state.h"
#include "player.h"
#include "enemy.h"
#include "pause_state.h"
#include "stats_tracker.h"
#include <iterator>

class GameState : public State{
public:
    GameState(sf::RenderWindow* window);
    ~GameState();
    void Render() noexcept override;
    void UpdateState(std::stack<State*>& states, sf::RenderWindow* window) noexcept override;
    
private:
    void InitState([[maybe_unused]] std::stack<State*>& states, sf::RenderWindow* window)noexcept override;
    static void UpdatePlayer()noexcept;
    static void UpdateObjects()noexcept;
    static void FreeDestroyedObjects();


    static Player* player;
    static std::vector<Object*> objects;
    StatsTracker* tracker;
};