#include "include/Input.hpp"

void Input::Init(){
    States InputStates;

    InputStates.FillWithValue(false);
}

void Input::UpdateMouse(SDL_Event *event) {
    States inputStates;

    if (event->type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
        switch (event->button.button) {
            case 1:
                inputStates.ChangeValue(true, 0);
                SDL_Log("MOUSE 1 %b", inputStates.MouseStates.at(0));
                break;
            case 2:
                inputStates.ChangeValue(true, 1);
                SDL_Log("MOUSE 2 %b", inputStates.MouseStates.at(1));
                break;
            case 3:
                inputStates.ChangeValue(true, 2);
                SDL_Log("MOUSE 3 %b", inputStates.MouseStates.at(2));
                break;
            default:
                break;
        }
    } else if (event->type == SDL_EVENT_MOUSE_BUTTON_UP) {
        switch (event->button.button) {
            case 1:
                inputStates.ChangeValue(false, 0);
                SDL_Log("MOUSE 1 %b", inputStates.MouseStates.at(0));
                break;
            case 2:
                inputStates.ChangeValue(false, 1);
                SDL_Log("MOUSE 2 %b", inputStates.MouseStates.at(1));
                break;
            case 3:
                inputStates.ChangeValue(false, 2);
                SDL_Log("MOUSE 3 %b", inputStates.MouseStates.at(2));
                break;
            default:
                break;
        }
    };
}