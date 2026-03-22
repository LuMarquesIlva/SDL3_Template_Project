project(
  'SDL_Template_Project',
  'cpp',
  version: '0.0.1',
  default_options: ['default_library=shared',
  'cpp_std=c++23,c++20,c++17'],
)

sdl3_dep = dependency('sdl3')
sdl3_ttf_dep = dependency('sdl3_ttf')
sdl3_image_dep = dependency('sdl3_image')
opencl_headers_dep = dependency('opencl-headers')
vulkan_headers_dep = dependency('VulkanHeaders', fallback: 'vulkan-headers')
glfw_dep = dependency('glfw3')

executable(
  meson.project_name(),
  sources: ['src/main.cpp', 'src/Entity.cpp', 'src/VectorFuncs.cpp'],
  include_directories: ['include'],
  c_args: ['-m64', '-lvulkan-1'],
  dependencies: [vulkan_headers_dep, sdl3_dep, sdl3_ttf_dep, sdl3_image_dep, glfw_dep, opencl_headers_dep],
)
