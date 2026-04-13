#pragma once

#include <Engine/Scenes/Scene.hpp>
#include <memory>
#include <optional>
#include <string>
#include <unordered_map>

namespace Engine::Scenes {
class Manager {
public:
    enum Error : std::uint8_t {
        SceneNotLoaded,
        SceneIsActive,
    };

    Manager() = default;
    ~Manager() = default;

    std::optional<std::shared_ptr<Scene>> LoadScene(const std::string& id);
    std::optional<std::shared_ptr<Scene>> GetScene(const std::string& id) const;
    std::optional<Manager::Error> UnloadScene(const std::string& id);

private:
    std::unordered_map<std::string, std::shared_ptr<Scene>> loadedScenes_;
};
}  // namespace Engine::Scenes
