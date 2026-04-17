#pragma once

#include <GE/Scenes/Scene.hpp>
#include <expected>
#include <functional>
#include <memory>
#include <optional>
#include <utility>

namespace GE::ECS {
//! \brief Helper class to manipulate the ECS in a easy way
class Entity {
public:
    enum Error : std::uint8_t {
        SceneIsUnloaded,
        ComponentAlreadyExist,
    };

    //! \brief Convert entt::entity to our Entity class
    //! \warning Don't use it directally, use the Scene CreateEntity()
    Entity(entt::entity entity, std::weak_ptr<Scenes::Scene> scene)
        : scene_(std::move(scene)), entity_(entity) {};
    ~Entity() = default;

    //! \brief Add a component to the entity
    //! \tparam TComponent Type of the component to be added
    //! \param args Arguments to be forwarded to TComponent contructor
    //! \return Reference of the added component if success
    //! \return Error enum value related to the issue
    template <typename TComponent, typename... TArgs>
    std::expected<std::reference_wrapper<TComponent>, Error> AddComponent(
        TArgs&&... args) {
        auto scene = this->GetSceneSafe();
        if (!scene.has_value()) {
            return std::unexpected(Error::SceneIsUnloaded);
        }

        auto& registry = scene.value()->registry_;

        auto hasComponent = this->HasComponent<TComponent>();
        if (!hasComponent.has_value()) {
            return std::unexpected(hasComponent.error());
        }
        if (hasComponent.value()) {
            return std::unexpected(Error::ComponentAlreadyExist);
        }

        return registry.emplace<TComponent>(this->entity_,
                                            std::forward<TArgs>(args)...);
    }

    //! \brief Remove a component from the entity
    //! If the entity don't has the component it'll be a noop
    //! \tparam TComponent Type of the component to be removed
    //! \return May return an Error if Scene is invalid
    template <typename TComponent>
    std::optional<Error> RemoveComponent() {
        auto scene = this->GetSceneSafe();
        if (!scene.has_value()) {
            return Error::SceneIsUnloaded;
        }

        auto& registry = scene.value()->registry_;

        registry.remove<TComponent>(this->entity_);
        return {};
    }

    //! \brief Check if entity has component
    //! \tparam TComponent Type of the component to be checked
    //! \return If the Entity has the TComponent
    //! \return Error enum value related to the issue
    template <typename TComponent>
    std::expected<bool, Error> HasComponent() {
        auto scene = this->GetSceneSafe();
        if (!scene.has_value()) {
            return std::unexpected(Error::SceneIsUnloaded);
        }

        const auto& registry = scene.value()->registry_;
        return registry.all_of<TComponent>(this->entity_);
    }

    //! \brief Get component from entity
    //! \tparam TComponent Type of the component to be get
    //! \return Component reference if exist
    //! \return Error enum value related to the issue
    template <typename TComponent>
    std::expected<std::optional<std::reference_wrapper<TComponent>>, Error>
    GetComponent() {
        auto scene = this->GetSceneSafe();
        if (!scene.has_value()) {
            return std::unexpected(Error::SceneIsUnloaded);
        }

        const auto& registry = scene.value()->registry_;
        if (!this->HasComponent<TComponent>().value()) {
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
}  // namespace GE::ECS
