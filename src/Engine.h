#pragma once

#include "AssetManager/AssetStore.h"
#include <SDL3/SDL.h>
#include <memory>

class Engine {
  public:
    Engine();
    ~Engine();

    void Run();
    void Setup();
    void PollEvents();
    void Update();
    void Render();
    void Destroy();

  private:
    SDL_Window *window_;
    SDL_Renderer *renderer_;

    std::unique_ptr<AssetStore> assetStore_;

    double lastFrameTime_;
    bool shouldClose_;
};
