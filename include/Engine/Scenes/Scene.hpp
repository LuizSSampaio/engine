#pragma once

#include <entt/entt.hpp>
#include <string>

namespace Engine::ECS {
class Entity;
}

namespace Engine::Scenes {
class Scene {
public:
    bool isActive;

    Scene(std::string id) : id_(std::move(id)) {};
    ~Scene() = default;

    void Setup();
    void Update();
    void Destroy();

private:
    std::string id_;
    entt::registry registry_;

    friend class Engine::ECS::Entity;
};
}  // namespace Engine::Scenes
