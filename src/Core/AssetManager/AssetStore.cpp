#include "AssetStore.h"

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

AssetStore::AssetStore() {}
AssetStore::~AssetStore() { this->Clear(); }

void AssetStore::AddAsset(SDL_Renderer *renderer, std::string id,
                          const std::string &filepath) {
    SDL_Surface *surface = IMG_Load(filepath.c_str());
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_DestroySurface(surface);

    this->data_.insert(std::pair(id, texture));
}

SDL_Texture *AssetStore::GetAsset(const std::string &id) const {
    return this->data_.at(id);
}

void AssetStore::DeleteAsset(const std::string &id) {
    SDL_DestroyTexture(this->data_.at(id));
    this->data_.erase(id);
}

void AssetStore::Clear() { this->data_.clear(); }
