#pragma once

#include <entt/entt.hpp>
#include <string>

namespace Engine::Scenes {
class Scene {
public:
    bool isActive;
    entt::registry registry;

    Scene(std::string id) : id_(std::move(id)) {};
    ~Scene() = default;

    void Setup();
    void Update();
    void Destroy();

private:
    std::string id_;
};
}  // namespace Engine::Scenes
