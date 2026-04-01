#include "Engine.h"

#include <iostream>

Engine::Engine() {}

Engine::~Engine() {}

void Engine::Run() {
    this->Setup();

    while (!this->shouldClose_) {
        this->Update();
        this->Render();
    }

    this->Destroy();
}

void Engine::Setup() {
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)) {
        std::cout << "Failed to initialize SDL3" << std::endl;
        return;
    }

    if (!SDL_CreateWindowAndRenderer("Game Engine", 800, 600,
                                     SDL_WINDOW_BORDERLESS |
                                         SDL_WINDOW_RESIZABLE,
                                     &this->window_, &this->renderer_)) {
        std::cout << "Failed to create a window and a renderer" << std::endl;
        return;
    }

    SDL_MaximizeWindow(this->window_);

    this->shouldClose_ = false;
}

void Engine::Update() {}

void Engine::Render() {
    SDL_SetRenderDrawColor(this->renderer_, 21, 21, 21, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(this->renderer_);

    SDL_RenderPresent(this->renderer_);
}

void Engine::Destroy() {}
