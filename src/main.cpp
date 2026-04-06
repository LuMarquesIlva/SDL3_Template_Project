#define SDL_MAIN_USE_CALLBACKS 1  /* use the callbacks instead of main() */
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "include/Entity.hpp"

/* We will use this renderer to draw into this window every frame. */
static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

Vector2 vec2 = Vector2(60.0, 40.0);

/* This function runs once at startup. */
SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
{
    SDL_SetAppMetadata("SDL3 Template", "1.0", "com.example.sdl-template");

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    if (!SDL_CreateWindowAndRenderer("Template SDL3", 640, 480, SDL_WINDOW_RESIZABLE, &window, &renderer)) {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    // Disables VSYNC to be compatible with older integrated GPUs
    if (SDL_SetRenderVSync(renderer, SDL_RENDERER_VSYNC_DISABLED) == false) {
    SDL_Log("Failed to disable VSync: %s", SDL_GetError());
    }

    SDL_SetRenderLogicalPresentation(renderer, 640, 480, SDL_LOGICAL_PRESENTATION_LETTERBOX);

    return SDL_APP_CONTINUE;  /* carry on with the program! */
}

Object obj(1, 40, 60, 30, 30);

/* This function runs when a new event (mouse input, keypresses, etc) occurs. */
SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{

    if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;  /* end the program, reporting success to the OS. */
    }

    if (event->type == SDL_EVENT_KEY_DOWN) {
        switch (event->key.key) {
        case SDL_Keycode(SDLK_W):
            obj.Rect.y -= 1;
            break;
        case SDL_Keycode(SDLK_A):
            obj.Rect.x -= 1;
            break;
        case SDL_Keycode(SDLK_S):
            obj.Rect.y += 1;
            SDL_Log("X: %f | Y: %f", obj.Rect.x, obj.Rect.y);
            break;
        case SDL_Keycode(SDLK_D):
            obj.Rect.x += 1;
            SDL_Log("X: %f | Y: %f", obj.Rect.x, obj.Rect.y);
            break;
        default:
            SDL_Log("Invalid Input");
            break;
        }
    }

    return SDL_APP_CONTINUE;  /* carry on with the program! */
}

/* This function runs once per frame, and is the heart of the program. */
SDL_AppResult SDL_AppIterate(void *appstate)
{
    const double now = ((double)SDL_GetTicks()) / 1000.0;  /* convert from milliseconds to seconds. */

    SDL_SetRenderDrawColorFloat(renderer, 0.3, 0.3, 0.3, SDL_ALPHA_OPAQUE_FLOAT);  /* new color, full alpha. */

    /* clear the window to the draw color. */
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColorFloat(renderer, 0.8, 0.8, 0.8, SDL_ALPHA_OPAQUE_FLOAT);

    SDL_RenderFillRect(renderer, &obj.Rect);

    /* put the newly-cleared rendering on the screen. */
    SDL_RenderPresent(renderer);

    return SDL_APP_CONTINUE;  /* carry on with the program! */
}

/* This function runs once at shutdown. */
void SDL_AppQuit(void *appstate, SDL_AppResult result)
{
    /* SDL will clean up the window/renderer for us. */
}