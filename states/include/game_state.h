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
    GameState(std::array<State*, 5>& states, sf::RenderWindow* window);
    ~GameState();
    void Render() noexcept override;
    void UpdateState(std::array<State*, 5>& states,long unsigned int& current_state) noexcept override;
    void InitState(std::array<State*, 5>& states)noexcept override;
    static Player* GetPlayer()noexcept;
private:
    static void UpdatePlayer()noexcept;
    static void UpdateObjects()noexcept;
    static void FreeDestroyedObjects();
    void CheckForGameOver(std::array<State*, 5>& states,long unsigned int& current_state)noexcept;
    void PlaySound()noexcept;
    
    static int enemies_count;
    static Player* player;
    static std::vector<Object*> objects;
    StatsTracker* tracker;
    static sf::RenderWindow* window_ptr;    

    static sf::SoundBuffer _sound_buffer[3];
    static sf::Sound _sound[3];
};