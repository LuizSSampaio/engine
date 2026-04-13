#pragma once

#include <Engine/Scenes/Scene.hpp>
#include <expected>
#include <memory>
#include <optional>
#include <utility>

namespace Engine::ECS {
class Entity {
public:
    enum Error {
        SceneIsUnloaded,
        ComponentAlreadyExist,
    };

    Entity(entt::entity entity, std::weak_ptr<Scenes::Scene> scene)
        : scene_(std::move(scene)), entity_(entity) {};
    ~Entity() = default;

    template <typename TComponent, typename... TArgs>
    std::expected<TComponent&, Error> AddComponent(TArgs&&... args) {
        auto scene = this->GetSceneSafe();
        if (!scene.has_value()) {
            return std::unexpected(Error::SceneIsUnloaded);
        }

        const auto& registry = scene.value()->registry_;

        if (this->HasComponent<TComponent>()) {
            return std::unexpected(Error::ComponentAlreadyExist);
        }

        return registry.emplace<TComponent>(this->entity_,
                                            std::forward<TArgs>(args)...);
    }

    template <typename TComponent>
    std::optional<Error> RemoveComponent() {
        auto scene = this->GetSceneSafe();
        if (!scene.has_value()) {
            return Error::SceneIsUnloaded;
        }

        const auto& registry = scene.value()->registry_;

        registry.remove<TComponent>(this->entity_);
        return {};
    }

    template <typename TComponent>
    std::expected<bool, Error> HasComponent() {
        auto scene = this->GetSceneSafe();
        if (!scene.has_value()) {
            return std::unexpected(Error::SceneIsUnloaded);
        }

        const auto& registry = scene.value()->registry_;
        return registry.all_of<TComponent>(this->entity_);
    }

    template <typename TComponent>
    std::expected<std::optional<TComponent&>, Error> GetComponent() {
        auto scene = this->GetSceneSafe();
        if (!scene.has_value()) {
            return std::unexpected(Error::SceneIsUnloaded);
        }

        const auto& registry = scene.value()->registry_;
        if (!this->HasComponent<TComponent>()) {
            return {};
        }

        return registry.get<TComponent>(this->entity_);
    }

private:
    std::weak_ptr<Scenes::Scene> scene_;
    entt::entity entity_;

    std::optional<std::shared_ptr<Scenes::Scene>> GetSceneSafe() {
        if (this->scene_.expired()) {
            return {};
        }

        return this->scene_.lock();
    }
};
}  // namespace Engine::ECS
