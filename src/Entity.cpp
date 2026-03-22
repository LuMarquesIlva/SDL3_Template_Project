#include "include/Entity.hpp"

SDL_FRect Object::createObject(float x, float y, float width, float height) {
    
    SDL_FRect obj = {x, y, height, width};

    return obj;
}
