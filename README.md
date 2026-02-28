# Amethyst Prebuilt Libraries

This repository stores the libraries amethyst uses.

## Why?

Because having all this stuff in the app repo bloats buildtimes, makes the repo clone huge, and just looks ugly for now. This makes debugging harder but the modularity makes it worth it

## Directories

The root directory contains the root project which takes all the AAR outputs of all the subprojects and puts it into `build/outputs/aar`.

Any mesa based AAR should be put under `renderers/mesa-libs/libs/<subproject_name>` for organization. Everything else should be self-explanatory, renderers go in the renderers, if you need to add a non-renderer, give it a folder.

## Building
Simply run `./gradlew assembleRelease`

- `lwjgl-build` requires you to `export JAVA8_HOME=path/to/java8` in order to build the natives.


# Licenses
___
* [Arcmetica DNS Injector](https://github.com/AngelAuraMC/amethyst-prebuilt-libraries/tree/master/misc/arc_dns_injector): [LGPLv3 License](https://github.com/AngelAuraMC/amethyst-prebuilt-libraries/blob/master/misc/arc_dns_injector/LICENSE)
* [GL4ES](https://github.com/AngelAuraMC/gl4es): [MIT License](https://github.com/ptitSeb/gl4es/blob/master/LICENSE).
* [krypton-wrapper](https://github.com/BZLZHH/NG-GL4ES): [MIT License](https://github.com/ptitSeb/gl4es/blob/master/LICENSE).
* [MobileGlues](https://github.com/MobileGL-Dev/MobileGlues): [LGPL-2.1 License](https://github.com/MobileGL-Dev/MobileGlues/blob/dev-es/LICENSE).
* [Mesa 3D Graphics Library](https://gitlab.freedesktop.org/mesa/mesa): [MIT License](https://docs.mesa3d.org/license.html), Other Licenses (Refer to source files SPDX headers).
* [GLXShim](https://github.com/Swung0x48/GLXShim) - Unknown License
* [libdrm](https://gitlab.freedesktop.org/mesa/libdrm) - [Refer to SPDX headers](https://gitlab.freedesktop.org/mesa/libdrm)
* [ANGLE](https://chromium.googlesource.com/angle/angle/): [ARR](https://chromium.googlesource.com/angle/angle/+/refs/heads/main/LICENSE)
* [imgui-java](https://github.com/SpaiR/imgui-java): [MIT License](https://github.com/SpaiR/imgui-java/blob/main/LICENSE)
* [zstd](https://github.com/facebook/zstd): [BSD License](https://github.com/facebook/zstd/blob/ae9f20ca2716f2605822ca375995b7d876389b64/LICENSE) or [GPLv2 License](https://github.com/facebook/zstd/blob/ae9f20ca2716f2605822ca375995b7d876389b64/COPYING)
* [SDL3](https://github.com/libsdl-org/SDL): [zlib License](https://github.com/libsdl-org/SDL/blob/main/LICENSE.txt)
* [sdl2-compat](https://github.com/libsdl-org/sdl2-compat): [zlib License](https://github.com/libsdl-org/sdl2-compat/blob/main/LICENSE.txt)
* [LWJGL3](https://github.com/AngelAuraMC/lwjgl3): [BSD-3 License](https://github.com/LWJGL/lwjgl3/blob/master/LICENSE.md).
* [LWJGLX](https://github.com/AngelAuraMC/lwjglx) (LWJGL2 API compatibility layer for LWJGL3): unknown license.
* [OpenAL-Soft](https://github.com/kcat/openal-soft): [GNU GPLv2](app_pojavlauncher/src/main/assets/licenses/OPENAL-SOFT_GPL2)
  * [oboe](https://github.com/google/oboe): [Apache License 2.0](app_pojavlauncher/src/main/assets/licenses/OBOE_APACHE2).
  * [pfffft](https://bitbucket.org/jpommier/pffft/src/master/): [ARR](app_pojavlauncher/src/main/assets/licenses/PFFFT_LICENSE)
