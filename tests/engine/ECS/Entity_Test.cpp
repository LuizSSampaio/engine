#include <doctest.h>

#include <GE/ECS/Entity.hpp>
#include <GE/Scenes/Scene.hpp>
#include <memory>

using namespace GE::ECS;

struct Position {
    float x, y;
    Position(float x = 0, float y = 0) : x(x), y(y) {}
};

struct Velocity {
    float x, y;
    Velocity(float dx = 0, float dy = 0) : x(dx), y(dy) {}
};

#define components Position, Velocity

TEST_SUITE_BEGIN("ECS/Entity");

TEST_CASE_TEMPLATE("Add component test", TComponent, components) {
    auto scene = std::make_shared<GE::Scenes::Scene>("test");
    auto entity = scene->CreateEntity();

    float xVal = GENERATE(10.0, 20.0, 30.0);
    float yVal = GENERATE(10.0, 20.0, 30.0);

    std::expected<std::reference_wrapper<TComponent>, Entity::Error> component =
        entity.AddComponent<TComponent>(xVal, yVal);

    if (!component.has_value()) {
        CAPTURE(static_cast<int>(component.error()));
        FAIL("");
    }

    CHECK_EQ(component.value().get().x, xVal);
    CHECK_EQ(component.value().get().y, yVal);
}

TEST_SUITE_END();
