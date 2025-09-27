#!/bin/bash
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR" || exit 1

../crossfiles/generate_libdrm-static_crossfiles.sh $1

meson setup ../drm "build-libdrm_static-aarch64-android" \
            --prefix=$PWD"/../libdrm_install_dir/drm-static-aarch64-android" \
            --cross-file "../crossfiles/libdrm-crossfile-aarch64-android" \
            -Ddefault_library=static \
            -Dintel=disabled \
            -Dradeon=disabled \
            -Damdgpu=disabled \
            -Dnouveau=disabled \
            -Dvmwgfx=disabled \
            -Dfreedreno=disabled \
            -Dvc4=disabled \
            -Detnaviv=disabled \
            -Dcairo-tests=disabled \
            -Dfreedreno-kgsl=false

meson setup ../drm "build-libdrm_static-armv7a-android" \
            --prefix=$PWD"/../libdrm_install_dir/drm-static-armv7a-android" \
            --cross-file "../crossfiles/libdrm-crossfile-armv7a-android" \
            -Ddefault_library=static \
            -Dintel=disabled \
            -Dradeon=disabled \
            -Damdgpu=disabled \
            -Dnouveau=disabled \
            -Dvmwgfx=disabled \
            -Dfreedreno=disabled \
            -Dvc4=disabled \
            -Detnaviv=disabled \
            -Dcairo-tests=disabled \
            -Dfreedreno-kgsl=false

meson setup ../drm "build-libdrm_static-x86-android" \
            --prefix=$PWD"/../libdrm_install_dir/drm-static-x86-android" \
            --cross-file "../crossfiles/libdrm-crossfile-x86-android" \
            -Ddefault_library=static \
            -Dintel=disabled \
            -Dradeon=disabled \
            -Damdgpu=disabled \
            -Dnouveau=disabled \
            -Dvmwgfx=disabled \
            -Dfreedreno=disabled \
            -Dvc4=disabled \
            -Detnaviv=disabled \
            -Dcairo-tests=disabled \
            -Dfreedreno-kgsl=false

meson setup ../drm "build-libdrm_static-x86_64-android" \
            --prefix=$PWD"/../libdrm_install_dir/drm-static-x86_64-android" \
            --cross-file "../crossfiles/libdrm-crossfile-x86_64-android" \
            -Ddefault_library=static \
            -Dintel=disabled \
            -Dradeon=disabled \
            -Damdgpu=disabled \
            -Dnouveau=disabled \
            -Dvmwgfx=disabled \
            -Dfreedreno=disabled \
            -Dvc4=disabled \
            -Detnaviv=disabled \
            -Dcairo-tests=disabled \
            -Dfreedreno-kgsl=false

ninja -C ./build-libdrm_static-aarch64-android install
ninja -C ./build-libdrm_static-armv7a-android install
ninja -C ./build-libdrm_static-x86-android install
ninja -C ./build-libdrm_static-x86_64-android install
