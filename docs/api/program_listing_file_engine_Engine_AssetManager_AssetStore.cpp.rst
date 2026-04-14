
.. _program_listing_file_engine_Engine_AssetManager_AssetStore.cpp:

Program Listing for File AssetStore.cpp
=======================================

|exhale_lsh| :ref:`Return to documentation for file <file_engine_Engine_AssetManager_AssetStore.cpp>` (``engine/Engine/AssetManager/AssetStore.cpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   #include <SDL3/SDL.h>
   #include <SDL3_image/SDL_image.h>
   
   #include <Engine/AssetManager/AssetStore.hpp>
   
   namespace AssetManager = Engine::AssetManager;
   
   AssetManager::AssetStore::~AssetStore() { this->Clear(); }
   
   void AssetManager::AssetStore::AddAsset(const std::string& id,
                                           SDL_Renderer* renderer,
                                           const std::string& filepath) {
       SDL_Surface* surface = IMG_Load(filepath.c_str());
       SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
       SDL_DestroySurface(surface);
   
       this->data_.insert(std::pair(id, texture));
   }
   
   SDL_Texture* AssetManager::AssetStore::GetAsset(const std::string& id) const {
       return this->data_.at(id);
   }
   
   void AssetManager::AssetStore::DeleteAsset(const std::string& id) {
       SDL_DestroyTexture(this->data_.at(id));
       this->data_.erase(id);
   }
   
   void AssetManager::AssetStore::Clear() { this->data_.clear(); }
