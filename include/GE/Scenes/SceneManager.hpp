#pragma once

#include <GE/Scenes/Scene.hpp>
#include <memory>
#include <optional>
#include <string>
#include <unordered_map>

namespace GE::Scenes {
class SceneManager {
public:
    enum Error : std::uint8_t {
        SceneNotLoaded,
        SceneIsActive,
    };

    SceneManager() = default;
    ~SceneManager() = default;

    std::optional<std::shared_ptr<Scene>> LoadScene(const std::string& id);
    std::optional<std::shared_ptr<Scene>> GetScene(const std::string& id) const;
    std::optional<SceneManager::Error> UnloadScene(const std::string& id);

private:
    std::unordered_map<std::string, std::shared_ptr<Scene>> loadedScenes_;
};
}  // namespace GE::Scenes
