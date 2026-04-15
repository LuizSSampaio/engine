#pragma once

#include <entt/entt.hpp>
#include <memory>
#include <string>

namespace GE::ECS {
class Entity;
}

namespace GE::Scenes {
class Scene : public std::enable_shared_from_this<Scene> {
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

    friend class ECS::Entity;
};
}  // namespace GE::Scenes
