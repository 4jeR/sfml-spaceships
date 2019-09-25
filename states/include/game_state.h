#pragma once
#include "state.h"
#include "player.h"
#include "enemy.h"
#include "stats_tracker.h"
#include "pause_state.h"
#include <iterator>
#include "sfml_headers.h"

class GameState : public State{
public:
    GameState(std::array<State*, 4>& states, sf::RenderWindow* window);
    ~GameState();
    void Render() noexcept override;
    void UpdateState(std::array<State*, 4>& states,long unsigned int& current_state) noexcept override;
    void InitState(std::array<State*, 4>& states)noexcept override;
    
private:
    static void UpdatePlayer()noexcept;
    static void UpdateObjects()noexcept;
    static void FreeDestroyedObjects();

    static int enemies_count;
    static Player* player;
    static std::vector<Object*> objects;
    StatsTracker* tracker;
    static sf::RenderWindow* window_ptr;    

    sf::SoundBuffer _sound_buffer;
    sf::Sound _sound;
};