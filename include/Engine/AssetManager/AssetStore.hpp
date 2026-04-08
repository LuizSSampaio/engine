#pragma once

#include <SDL3/SDL.h>
#include <string>
#include <unordered_map>

namespace Engine::AssetManager {
class AssetStore {
  public:
    AssetStore();
    ~AssetStore();

    void AddAsset(SDL_Renderer *renderer, std::string id,
                  const std::string &filepath);
    SDL_Texture *GetAsset(const std::string &id) const;
    void DeleteAsset(const std::string &id);
    void Clear();

  private:
    std::unordered_map<std::string, SDL_Texture *> data_;
};
} // namespace Engine::AssetManager
