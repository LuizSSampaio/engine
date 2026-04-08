#include "Core.hpp"

#include "AssetManager/AssetStore.hpp"
#include "Logger.hpp"
#include <memory>

Core::Core() {
    this->logger_ =
        std::make_unique<Logger>(Logger::Stdout{}, Logger::Stdout{});
    this->assetStore_ = std::make_unique<AssetStore>();
}

Core::~Core() {}

void Core::Run() {
    this->Setup();

    while (!this->shouldClose_) {
        double deltaTime = (SDL_GetTicks() - this->lastFrameTime_) / 1000.0;
        this->lastFrameTime_ = SDL_GetTicks();

        this->PollEvents();
        this->Update();
        this->Render();
    }

    this->Destroy();
}

void Core::Setup() {
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)) {
        LOG_CORE_CRITICAL("Failed initialize SDL3");
        return;
    }

    if (!SDL_CreateWindowAndRenderer("Game Engine", 800, 600,
                                     SDL_WINDOW_BORDERLESS |
                                         SDL_WINDOW_RESIZABLE,
                                     &this->window_, &this->renderer_)) {

        LOG_CORE_CRITICAL("Failed to create window/renderer");
        return;
    }

    SDL_MaximizeWindow(this->window_);

    this->shouldClose_ = false;
}

void Core::PollEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_EVENT_QUIT:
            this->shouldClose_ = true;
            break;
        default:
            break;
        }
    }
}

void Core::Update() {}

void Core::Render() {
    SDL_SetRenderDrawColor(this->renderer_, 21, 21, 21, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(this->renderer_);

    SDL_RenderPresent(this->renderer_);
}

void Core::Destroy() {}
