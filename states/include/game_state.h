#pragma once
#include "state.h"
#include "player.h"
#include "enemy.h"
#include "pause_state.h"
#include "stats_tracker.h"
#include <iterator>

class GameState : public State{
public:
    GameState(std::array<State*, 3>& states, sf::RenderWindow* window);
    ~GameState();
    void Render() noexcept override;
    void UpdateState(std::array<State*, 3>& states,long unsigned int& current_state, sf::RenderWindow* window) noexcept override;
    void InitState(std::array<State*, 3>& states, sf::RenderWindow* window)noexcept override;
    
private:
    static void UpdatePlayer()noexcept;
    static void UpdateObjects()noexcept;
    static void FreeDestroyedObjects();


    static Player* player;
    static std::vector<Object*> objects;
    StatsTracker* tracker;
};