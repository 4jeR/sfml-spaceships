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
    void UpdateState(std::array<State*, 3>& states,long unsigned int& current_state) noexcept override;
    void InitState(std::array<State*, 3>& states)noexcept override;
    
private:
    static void UpdatePlayer()noexcept;
    static void UpdateObjects()noexcept;
    static void FreeDestroyedObjects();

    static int enemies_count;
    static Player* player;
    static std::vector<Object*> objects;
    StatsTracker* tracker;
    static sf::RenderWindow* window_ptr;
};