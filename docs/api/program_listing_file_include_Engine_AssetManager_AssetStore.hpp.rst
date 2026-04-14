
.. _program_listing_file_include_Engine_AssetManager_AssetStore.hpp:

Program Listing for File AssetStore.hpp
=======================================

|exhale_lsh| :ref:`Return to documentation for file <file_include_Engine_AssetManager_AssetStore.hpp>` (``include/Engine/AssetManager/AssetStore.hpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   #pragma once
   
   #include <SDL3/SDL.h>
   
   #include <string>
   #include <unordered_map>
   
   namespace Engine::AssetManager {
   class AssetStore {
   public:
       AssetStore() = default;
       ~AssetStore();
   
       void AddAsset(const std::string& id, SDL_Renderer* renderer,
                     const std::string& filepath);
       SDL_Texture* GetAsset(const std::string& id) const;
       void DeleteAsset(const std::string& id);
       void Clear();
   
   private:
       std::unordered_map<std::string, SDL_Texture*> data_;
   };
   }  // namespace Engine::AssetManager
