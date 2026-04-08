#pragma once

#include <string>

namespace Engine::Scenes {
class Scene {
  public:
    Scene(std::string id) : id_(id) {};
    ~Scene() = default;

  private:
    std::string id_;
};
} // namespace Engine::Scenes
