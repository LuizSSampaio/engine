project('engine', 'cpp', default_options: ['default_library=static', 'cpp_std=c++23'])

sdl3_dep = dependency('sdl3')
sdl3_image_dep = dependency('sdl3_image')
sdl3_ttf_dep = dependency('sdl3_ttf')
spdlog = dependency('spdlog')

engine_lib_dep = declare_dependency(
  dependencies: [sdl3_dep, sdl3_image_dep, sdl3_ttf_dep, spdlog],
)

engine_lib = shared_library(meson.project_name(), 'src/Core/Core.cpp', 'src/Core/AssetManager/AssetStore.cpp',
           dependencies: engine_lib_dep)

executable(meson.project_name(), 'src/EntryPoint.cpp', dependencies: engine_lib_dep, link_with: [engine_lib])
