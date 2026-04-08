project(
  'SDL3_Template_Project',
  'cpp',
  meson_version: '>=1.1.0',
  version: '0.0.1',
  default_options: ['default_library=static',
  'cpp_std=c++23,c++20,c++17'],
)

cc = meson.get_compiler('c')
cxx = meson.get_compiler('cpp')


sdl3_dep = dependency('sdl3')
sdl3_ttf_dep = dependency('sdl3_ttf')
sdl3_image_dep = dependency('sdl3_image')
glfw_dep = dependency('glfw3')

# if you want opencl lib uncomment the <dep> and add it to the dependencies
#opencl_headers_dep = dependency('opencl-headers')

# if you want vulkan lib uncomment it and add the <dep> to the dependencies
#vulkan_headers_dep = dependency('VulkanHeaders', fallback: 'vulkan-headers')

if host_machine.system() == 'windows'
  message('SYSTEM IS WINDOWS')
  win = import('windows')
  #manifest = meson.project_name() + '.manifest'
  icon = 'icon.rc'
  res_file = win.compile_resources(icon)
  #manifest_file = win.compile_resources(manifest)
  
  executable(
    meson.project_name(),
    sources: ['src/main.cpp', 'src/Entity.cpp', 'src/VectorFuncs.cpp'],
    include_directories: ['include'],
    objects: [res_file],
    c_args: ['-D_WIN32'],
    dependencies: [sdl3_dep, sdl3_ttf_dep, sdl3_image_dep, glfw_dep],
  )
else
  executable(
    meson.project_name(),
    sources: ['src/main.cpp', 'src/Entity.cpp', 'src/VectorFuncs.cpp'],
    include_directories: ['include'],
    dependencies: [sdl3_dep, sdl3_ttf_dep, sdl3_image_dep, glfw_dep],
  )
endif

