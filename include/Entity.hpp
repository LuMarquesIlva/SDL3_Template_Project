#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <iostream>
#include <string>
#include <array>

#include <SDL3/SDL_rect.h>

#include "include/VectorFuncs.hpp"

class Object {
public:
    float ID = 0;
    float x;
    float y;
    SDL_FRect Rect;

    // Object Class Constructor: Uses the values to create an Object type, a sort of container
    // for SDL_FRect to make it easy to add values a properties
    Object(float ID, float x, float y, float w, float h) : ID(ID), x(x), y(y) {
        std::array<float, 3> ObjProperties = {ID, x, y};
        SDL_FRect Rect = {ObjProperties[1], ObjProperties[2], w, h};

        Object::Rect = Rect;
    };

};

#endif