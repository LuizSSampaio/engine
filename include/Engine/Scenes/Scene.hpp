#pragma once

#include <entt/entt.hpp>
#include <string>

namespace Engine::Scenes {
class Scene {
  public:
    bool isActive;
    entt::registry registry_;

    Scene(std::string id) : id_(id) {};
    ~Scene() = default;

    void Setup();
    void Update();
    void Destroy();

  private:
    std::string id_;
};
} // namespace Engine::Scenes
