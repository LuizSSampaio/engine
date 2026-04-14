#pragma once

#include <SDL3/SDL.h>

#include <string>
#include <unordered_map>

namespace GE::AssetManager {
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
}  // namespace GE::AssetManager
