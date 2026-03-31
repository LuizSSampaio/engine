#include <SDL3/SDL.h>
#include <iostream>

int main(int argc, char *argv[]) {
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)) {
        std::cout << "Failed to initialize SDL3" << std::endl;
        return -1;
    }

    SDL_Window *window;
    SDL_Renderer *renderer;
    if (!SDL_CreateWindowAndRenderer(
            "Game Engine", 800, 600,
            SDL_WINDOW_BORDERLESS | SDL_WINDOW_RESIZABLE, &window, &renderer)) {
        std::cout << "Failed to create a window and a renderer" << std::endl;
    }

    SDL_MaximizeWindow(window);

    while (true) {
        SDL_SetRenderDrawColor(renderer, 21, 21, 21, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);
    }

    return 0;
}
