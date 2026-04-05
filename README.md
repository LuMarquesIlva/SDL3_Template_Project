# Use Meson

You need __Meson__ to compile the project,
after installing it and it's dependencies
use the commands below

__DO NOT FORGET__, hydrate yourself 🍉

__base meson setup project__
```bash
meson setup build
cd build
meson compile
```


## -- // Dependencies // --

```txt
sdl3
sdl3_ttf
sdl3_image
glfw3
vulkan-headers
opencl-headers
```

# __IF WORKING WITH TERMUX__

install these packages using normal pkg system
```bash
pkg i sdl3 build-essentials ninja wine-stable llvm-mingw-w64
```
and __if cross compiling for windows__ install sdl3, freetype2 and glfw with wrap and then setup with
```bash
meson setup --cross-file x86_64-w64-mingw32.txt <build-dir>
```

I recommend using code-server package if using termux as you can configure for LAN connection and connect with a browser