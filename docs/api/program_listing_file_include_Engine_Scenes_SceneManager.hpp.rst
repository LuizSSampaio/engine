
.. _program_listing_file_include_Engine_Scenes_SceneManager.hpp:

Program Listing for File SceneManager.hpp
=========================================

|exhale_lsh| :ref:`Return to documentation for file <file_include_Engine_Scenes_SceneManager.hpp>` (``include/Engine/Scenes/SceneManager.hpp``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   #pragma once
   
   #include <Engine/Scenes/Scene.hpp>
   #include <memory>
   #include <optional>
   #include <string>
   #include <unordered_map>
   
   namespace Engine::Scenes {
   class Manager {
   public:
       enum Error : std::uint8_t {
           SceneNotLoaded,
           SceneIsActive,
       };
   
       Manager() = default;
       ~Manager() = default;
   
       std::optional<std::shared_ptr<Scene>> LoadScene(const std::string& id);
       std::optional<std::shared_ptr<Scene>> GetScene(const std::string& id) const;
       std::optional<Manager::Error> UnloadScene(const std::string& id);
   
   private:
       std::unordered_map<std::string, std::shared_ptr<Scene>> loadedScenes_;
   };
   }  // namespace Engine::Scenes
