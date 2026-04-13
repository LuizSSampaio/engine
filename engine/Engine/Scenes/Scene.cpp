#include <Engine/ECS/Entity.hpp>
#include <Engine/Scenes/Scene.hpp>

using namespace Engine::Scenes;

void Scene::Setup() {}

void Scene::Update() {}

void Scene::Destroy() {}

Engine::ECS::Entity Scene::CreateEntity() {
    auto entity = this->registry_.create();
    return {entity, this->weak_from_this()};
}
