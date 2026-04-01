project('engine', 'cpp', default_options: 'default_library=static')

sdl3_dep = dependency('sdl3')
sdl3_image_dep = dependency('sdl3_image')
sdl3_ttf_dep = dependency('sdl3_ttf')
spdlog = dependency('spdlog')

executable(meson.project_name(), 'src/Main.cpp', 'src/Engine.cpp',
           dependencies: [sdl3_dep, sdl3_image_dep, sdl3_ttf_dep, spdlog])
