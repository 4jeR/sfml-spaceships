#pragma once
#include "sfml_headers.h"
#include <vector>

class State{
public:
    State();
    virtual ~State();
    
protected:
    std::vector<sf::Texture> _textures;
};