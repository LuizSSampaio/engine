
.. _program_listing_file_include_GE_Scenes_Scene.hpp:

Program Listing for File Scene.hpp
==================================

|exhale_lsh| :ref:`Return to documentation for file <file_include_GE_Scenes_Scene.hpp>` (``include/GE/Scenes/Scene.hpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   #pragma once
   
   #include <entt/entt.hpp>
   #include <memory>
   #include <string>
   
   namespace GE::ECS {
   class Entity;
   }
   
   namespace GE::Scenes {
   class Scene : std::enable_shared_from_this<Scene> {
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
