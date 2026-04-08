#pragma once

#include <Engine/Scenes/Scene.hpp>
#include <optional>
#include <string>
#include <unordered_map>

namespace Engine::Scenes {
class Manager {
  public:
    Manager() = default;
    ~Manager() = default;

    std::optional<Scene &> LoadScene(std::string id);
    void UnloadScene(std::string id);

  private:
    std::unordered_map<std::string, Scene> loadedScenes_;
};
} // namespace Engine::Scenes
