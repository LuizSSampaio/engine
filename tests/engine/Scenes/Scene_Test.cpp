#include <doctest.h>

#include <GE/ECS/Entity.hpp>
#include <GE/Scenes/Scene.hpp>

using namespace GE::Scenes;

TEST_SUITE_BEGIN("Scenes/Scene");

TEST_CASE("Test Entity creation") {
    auto scene = Scene("test");
    CHECK_NOTHROW(scene.CreateEntity());
}

TEST_SUITE_END();
