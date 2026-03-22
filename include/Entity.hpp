#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <iostream>
#include <string>

#include <SDL3/SDL_rect.h>

#include "include/VectorFuncs.hpp"

class Object {
public:
    int ID = 0;
    float x;
    float y;
    std::vector<float> position(float, float);

    SDL_FRect createObject(float, float, float, float);
};

#endif