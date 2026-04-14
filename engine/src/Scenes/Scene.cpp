#include <GE/ECS/Entity.hpp>
#include <GE/Scenes/Scene.hpp>

using namespace GE::Scenes;

void Scene::Setup() {}

void Scene::Update() {}

void Scene::Destroy() {}

GE::ECS::Entity Scene::CreateEntity() {
    auto entity = this->registry_.create();
    return {entity, this->weak_from_this()};
}
