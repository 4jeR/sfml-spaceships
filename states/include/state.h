#pragma once
#include "sfml_headers.h"
#include <vector>

class State{
public:
    State(sf::RenderWindow* window);
    virtual ~State();
    virtual void Render() noexcept = 0;
    virtual void UpdateState(const float& dt) noexcept = 0;
    virtual void QuitState()noexcept = 0;
    virtual void InitState()noexcept = 0;
protected:
    sf::RenderWindow* _window;
    std::vector<sf::Texture> _textures;
};