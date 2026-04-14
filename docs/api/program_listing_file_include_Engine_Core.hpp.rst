
.. _program_listing_file_include_Engine_Core.hpp:

Program Listing for File Core.hpp
=================================

|exhale_lsh| :ref:`Return to documentation for file <file_include_Engine_Core.hpp>` (``include/Engine/Core.hpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   #pragma once
   
   #include <SDL3/SDL.h>
   
   #include <Engine/AssetManager/AssetStore.hpp>
   #include <Engine/Logger.hpp>
   #include <memory>
   
   namespace Engine {
   class Core {
   public:
       Core();
       ~Core() = default;
   
       void Run();
       void Setup();
       void PollEvents();
       void Update();
       void Render();
       void Destroy();
   
   private:
       SDL_Window* window_;
       SDL_Renderer* renderer_;
   
       std::unique_ptr<AssetManager::AssetStore> assetStore_;
       std::unique_ptr<Logger> logger_;
   
       double lastFrameTime_;
       bool shouldClose_;
   };
   }  // namespace Engine
