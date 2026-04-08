#pragma once

#include <Engine/AssetManager/AssetStore.hpp>
#include <Engine/Logger.hpp>
#include <SDL3/SDL.h>
#include <memory>

namespace Engine {
class Core {
  public:
    Core();
    ~Core();

    void Run();
    void Setup();
    void PollEvents();
    void Update();
    void Render();
    void Destroy();

  private:
    SDL_Window *window_;
    SDL_Renderer *renderer_;

    std::unique_ptr<AssetManager::AssetStore> assetStore_;
    std::unique_ptr<Logger> logger_;

    double lastFrameTime_;
    bool shouldClose_;
};
} // namespace Engine
