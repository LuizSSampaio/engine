#include <GE/AssetManager/AssetStore.hpp>
#include <GE/Core.hpp>
#include <GE/Logger.hpp>
#include <memory>

using namespace GE;

Core::Core() {
    this->logger_ =
        std::make_unique<Logger>(Logger::Stdout{}, Logger::Stdout{});
    this->assetStore_ = std::make_unique<AssetManager::AssetStore>();
}

void Core::Run() {
    this->Setup();

    while (!this->shouldClose_) {
        constexpr double secsToMilli = 1000.0;
        double deltaTime =
            (static_cast<double>(SDL_GetTicks()) - this->lastFrameTime_) /
            secsToMilli;
        this->lastFrameTime_ = static_cast<double>(SDL_GetTicks());

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

    constexpr int defaultWindowWidth = 800;
    constexpr int defaultWindowHeight = 600;
    if (!SDL_CreateWindowAndRenderer(
            "Game Engine", defaultWindowWidth, defaultWindowHeight,
            SDL_WINDOW_BORDERLESS | SDL_WINDOW_RESIZABLE, &this->window_,
            &this->renderer_)) {
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
