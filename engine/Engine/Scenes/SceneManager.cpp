#include <Engine/Scenes/SceneManager.hpp>
#include <utility>

#include "Engine/Logger.hpp"

using namespace Engine::Scenes;

std::optional<std::shared_ptr<Scene>> Manager::LoadScene(
    const std::string& id) {
    auto scene = std::make_shared<Scene>(id);
    this->loadedScenes_.insert(std::make_pair(id, scene));

    return scene;
}

std::optional<std::shared_ptr<Scene>> Manager::GetScene(
    const std::string& id) const {
    if (!this->loadedScenes_.contains(id)) {
        return {};
    }

    return this->loadedScenes_.at(id);
}

// TODO: Create a destroy queue to be cleaned at the end of the frame
std::optional<Manager::Error> Manager::UnloadScene(const std::string& id) {
    if (!this->loadedScenes_.contains(id)) {
        return Error::SceneNotLoaded;
    }

    auto scene = this->loadedScenes_.at(id);
    if (scene->isActive) {
        LOG_CORE_ERROR(
            "Scene({}) can't be unloaded. It's impossible to unload "
            "an active scene.",
            id);
        return Error::SceneIsActive;
    }

    scene->Destroy();
    this->loadedScenes_.erase(id);
    return {};
}
