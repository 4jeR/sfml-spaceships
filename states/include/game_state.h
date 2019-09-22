#pragma once
#include "state.h"
#include "player.h"

class GameState : public State{
public:
    GameState(sf::RenderWindow* window);
    ~GameState();
    void Render() noexcept override;
    void UpdateState(const float& dt) noexcept override;
    
private:
    void QuitState()noexcept override;
    void InitState()noexcept override;
    static void Render(const std::vector<Object*>& objects) noexcept;
    static void FreeMemory(std::vector<Object*>& objVec);
    static void UpdatePlayer()noexcept;
    static void UpdateObjects()noexcept;
    
    static Player* player;
    static std::vector<Object*> objects;

};