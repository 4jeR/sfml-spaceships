#pragma once
#include "state.h"
#include "player.h"
#include "enemy.h"

class GameState : public State{
public:
    GameState(sf::RenderWindow* window);
    ~GameState();
    void Render() noexcept override;
    void UpdateState() noexcept override;
    
private:
    static void UpdatePlayer()noexcept;
    static void UpdateObjects()noexcept;

    static void Render(const std::vector<Object*>& objects) noexcept;
    static void FreeMemory(std::vector<Object*>& objVec);
    bool CheckForQuit()noexcept override;
    void InitState()noexcept override;


    static Player* player;
    static std::vector<Object*> objects;
};