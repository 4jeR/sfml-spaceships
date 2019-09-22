#pragma once
#include "sfml_headers.h"
#include <vector>

class State{
public:
    State();
    virtual ~State();
    virtual void Render() noexcept = 0;
    virtual void UpdateAll() noexcept = 0;
protected:
    std::vector<sf::Texture> _textures;
};