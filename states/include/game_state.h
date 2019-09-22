#pragma once
#include "state.h"
#include "player.h"
#include "enemy.h"
#include <iterator>

class GameState : public State{
public:
    GameState(sf::RenderWindow* window);
    ~GameState();
    void Render() noexcept override;
    void UpdateState() noexcept override;
    
private:
    static void UpdatePlayer()noexcept;
    static void UpdateObjects()noexcept;
    static void FreeDestroyedObjects();
    static void FreeMemory();
    bool CheckForQuit()noexcept override;
    void InitState()noexcept override;


    static Player* player;
    static std::vector<Object*> objects;
};