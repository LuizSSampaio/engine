
.. _program_listing_file_engine_Engine_Scenes_Scene.cpp:

Program Listing for File Scene.cpp
==================================

|exhale_lsh| :ref:`Return to documentation for file <file_engine_Engine_Scenes_Scene.cpp>` (``engine/Engine/Scenes/Scene.cpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

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
