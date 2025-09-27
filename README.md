# Amethyst Prebuilt Libraries

This repository stores the libraries amethyst uses.

## Why?

Because having all this stuff in the app repo bloats buildtimes, makes the repo clone huge, and just looks ugly for now. This makes debugging harder but the modularity makes it worth it

## Directories

The root directory contains the root project which takes all the AAR outputs of all the subprojects and puts it into `build/outputs/aar`.

Any mesa based AAR should be put under `renderers/mesa-libs/libs/<subproject_name>` for organization. Everything else should be self-explanatory, renderers go in the renderers, if you need to add a non-renderer, give it a folder.

# Licenses
___
* [GL4ES](https://github.com/AngelAuraMC/gl4es): [MIT License](https://github.com/ptitSeb/gl4es/blob/master/LICENSE).
* [MobileGlues](https://github.com/MobileGL-Dev/MobileGlues): [LGPL-2.1 License](https://github.com/MobileGL-Dev/MobileGlues/blob/dev-es/LICENSE).
* [Mesa 3D Graphics Library](https://gitlab.freedesktop.org/mesa/mesa): [MIT License](https://docs.mesa3d.org/license.html), Other Licenses (Refer to source files SPDX headers).
* [GLXShim](https://github.com/Swung0x48/GLXShim) - Unknown License
* [libdrm](https://gitlab.freedesktop.org/mesa/libdrm) - [Refer to SPDX headers](https://gitlab.freedesktop.org/mesa/libdrm)
* [SDL3](https://github.com/libsdl-org/SDL): [zlib License](https://github.com/libsdl-org/SDL/blob/main/LICENSE.txt)
* [sdl2-compat](https://github.com/libsdl-org/sdl2-compat): [zlib License](https://github.com/libsdl-org/sdl2-compat/blob/main/LICENSE.txt)