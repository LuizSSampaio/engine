#pragma once

#include <SDL3/SDL.h>

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

    double lastFrameTime_;
    bool shouldClose_;
};
