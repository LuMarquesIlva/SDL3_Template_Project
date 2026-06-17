#ifndef INPUT_HPP
#define INPUT_HPP

#include "include/VectorFuncs.hpp"
#include <array>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_mouse.h>
#include <SDL3/SDL_log.h>

class Input 
{
    public:
        struct States {
            std::array<bool, 5> MouseStates;
            std::array<bool, 5> KeyboardStates;

            void ChangeValue(bool value, int index) {
                MouseStates[index] = value;
            };

            void FillWithValue(bool value) {
                for (int i = 0; i < (int)MouseStates.size(); i++) {
                    MouseStates[i] = value;
                };
            };

            bool IsButtonDown(int index) {
                if (MouseStates[index-1] == true) {
                    return true;
                };
                return false;
            };
        };

        void Init();
        
        void UpdateMouse(SDL_Event *event);
        //explicit operator SDL_Event *() const { return InputEvents; };
        
};

#endif