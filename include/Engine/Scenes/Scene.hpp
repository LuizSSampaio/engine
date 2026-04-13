#pragma once

#include <entt/entt.hpp>
#include <memory>
#include <string>

namespace Engine::ECS {
class Entity;
}

namespace Engine::Scenes {
class Scene : std::enable_shared_from_this<Scene> {
public:
    bool isActive;

    Scene(std::string id) : id_(std::move(id)) {};
    ~Scene() = default;

    void Setup();
    void Update();
    void Destroy();

    ECS::Entity CreateEntity();

private:
    std::string id_;
    entt::registry registry_;

    friend class Engine::ECS::Entity;
};
}  // namespace Engine::Scenes
