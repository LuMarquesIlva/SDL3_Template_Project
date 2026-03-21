project(
  'VulkanAR_Template',
  'cpp',
  version: '0.0.1',
  default_options: ['default_library=shared', 'cpp_std=c++23,c++20,c++17'],
)

sdl3_dep = dependency('sdl3')
sdl3_ttf_dep = dependency('sdl3_ttf')
sdl3_image_dep = dependency('sdl3_image')
opencl_headers_dep = dependency('opencl-headers')
vulkan_headers_dep = dependency('VulkanHeaders')
glfw_dep = dependency('glfw3')

executable(
  'VulkanAR_Template',
  'src/main.cpp',
  dependencies: [sdl3_dep, sdl3_ttf_dep, sdl3_image_dep, opencl_headers_dep, vulkan_headers_dep, glfw_dep],
)
