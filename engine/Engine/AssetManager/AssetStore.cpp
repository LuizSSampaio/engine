#include <Engine/AssetManager/AssetStore.hpp>

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

namespace AssetManager = Engine::AssetManager;

AssetManager::AssetStore::AssetStore() {}
AssetManager::AssetStore::~AssetStore() { this->Clear(); }

void AssetManager::AssetStore::AddAsset(SDL_Renderer *renderer, std::string id,
                                        const std::string &filepath) {
    SDL_Surface *surface = IMG_Load(filepath.c_str());
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_DestroySurface(surface);

    this->data_.insert(std::pair(id, texture));
}

SDL_Texture *AssetManager::AssetStore::GetAsset(const std::string &id) const {
    return this->data_.at(id);
}

void AssetManager::AssetStore::DeleteAsset(const std::string &id) {
    SDL_DestroyTexture(this->data_.at(id));
    this->data_.erase(id);
}

void AssetManager::AssetStore::Clear() { this->data_.clear(); }
