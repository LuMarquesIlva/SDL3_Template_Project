#include "include/Input.hpp"

void Input::Init(){
    States inputStates;
    struct States *ptr = &inputStates;

    ptr->FillWithValue(false);
}

void Input::UpdateMouse(SDL_Event *event) {
    States inputStates;
    struct States *ptr = &inputStates;

    if (event->type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
        switch (event->button.button) {
            case 1:
                ptr->ChangeValue(true, 0);
                SDL_Log("MOUSE 1 %b", ptr->MouseStates.at(0));
                break;
            case 2:
                ptr->ChangeValue(true, 1);
                SDL_Log("MOUSE 2 %b", ptr->MouseStates.at(1));
                break;
            case 3:
                ptr->ChangeValue(true, 2);
                SDL_Log("MOUSE 3 %b", ptr->MouseStates.at(2));
                break;
            default:
                break;
        }
    } else if (event->type == SDL_EVENT_MOUSE_BUTTON_UP) {
        switch (event->button.button) {
            case 1:
                ptr->ChangeValue(false, 0);
                SDL_Log("MOUSE 1 %b", ptr->MouseStates.at(0));
                break;
            case 2:
                ptr->ChangeValue(false, 1);
                SDL_Log("MOUSE 2 %b", ptr->MouseStates.at(1));
                break;
            case 3:
                ptr->ChangeValue(false, 2);
                SDL_Log("MOUSE 3 %b", ptr->MouseStates.at(2));
                break;
            default:
                break;
        }
    };
}