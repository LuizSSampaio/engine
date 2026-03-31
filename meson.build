project('engine', 'cpp', default_options: 'default_library=static')

sdl3_dep = dependency('sdl3')
sdl3_image_dep = dependency('sdl3_image')
sdl3_ttf_dep = dependency('sdl3_ttf')

executable(meson.project_name(), 'src/main.cpp',
           dependencies: [sdl3_dep, sdl3_image_dep, sdl3_ttf_dep])
