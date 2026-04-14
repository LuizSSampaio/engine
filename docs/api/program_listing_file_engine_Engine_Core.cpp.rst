
.. _program_listing_file_engine_Engine_Core.cpp:

Program Listing for File Core.cpp
=================================

|exhale_lsh| :ref:`Return to documentation for file <file_engine_Engine_Core.cpp>` (``engine/Engine/Core.cpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   #include <Engine/AssetManager/AssetStore.hpp>
   #include <Engine/Core.hpp>
   #include <Engine/Logger.hpp>
   #include <memory>
   
   Engine::Core::Core() {
       this->logger_ =
           std::make_unique<Logger>(Logger::Stdout{}, Logger::Stdout{});
       this->assetStore_ = std::make_unique<AssetManager::AssetStore>();
   }
   
   void Engine::Core::Run() {
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
   
   void Engine::Core::Setup() {
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
   
   void Engine::Core::PollEvents() {
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
   
   void Engine::Core::Update() {}
   
   void Engine::Core::Render() {
       SDL_SetRenderDrawColor(this->renderer_, 21, 21, 21, SDL_ALPHA_OPAQUE);
       SDL_RenderClear(this->renderer_);
   
       SDL_RenderPresent(this->renderer_);
   }
   
   void Engine::Core::Destroy() {}
