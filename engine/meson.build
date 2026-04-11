sdl3_dep = dependency('sdl3')
sdl3_image_dep = dependency('sdl3_image')
sdl3_ttf_dep = dependency('sdl3_ttf')
spdlog_dep = dependency('spdlog')
entt_dep = dependency('entt')

engine_lib_dep = declare_dependency(
  dependencies: [sdl3_dep, sdl3_image_dep, sdl3_ttf_dep, spdlog_dep, entt_dep],
  include_directories : incdir,
)

engine_lib = library(meson.project_name(),
                     'Engine/Core.cpp', 'Engine/AssetManager/AssetStore.cpp',
                     'Engine/Scenes/SceneManager.cpp', 'Engine/Scenes/Scene.cpp',
                     dependencies: engine_lib_dep)

engine_exec = executable(meson.project_name(), 'EntryPoint.cpp', dependencies: engine_lib_dep, link_with: [engine_lib])
