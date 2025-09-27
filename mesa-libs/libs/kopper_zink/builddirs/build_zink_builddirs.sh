#!/bin/bash
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR" || exit 1

./build_libdrm-static_builddirs.sh $1
../crossfiles/generate_zink_crossfiles.sh $1

meson setup ../../../mesa/ "build-kopper_zink-aarch64-android" \
            --prefix=$PWD"/../kopper_zink_install_dir/kopper_zink-arm64-v8a-android" \
            --cross-file "../crossfiles/mesa-crossfile-aarch64-android" \
            -Dplatforms=android \
            -Dplatform-sdk-version=30 \
            -Dandroid-stub=true \
            -Dxlib-lease=disabled \
            -Degl=enabled \
            -Dgbm=disabled \
            -Dglx=disabled \
            -Dllvm=disabled \
            -Dopengl=true \
            -Dvulkan-drivers= \
            -Dgallium-drivers=zink \
            -Dzstd=disabled \
            -Dglvnd=false \
            -Degl-lib-suffix=_mesa \
            -Dbuildtype=release

meson setup ../../../mesa/ "build-kopper_zink-armv7a-android" \
            --prefix=$PWD"/../kopper_zink_install_dir/kopper_zink-armeabi-v7a-android" \
            --cross-file "../crossfiles/mesa-crossfile-armv7a-android" \
            -Dplatforms=android \
            -Dplatform-sdk-version=26 \
            -Dandroid-stub=true \
            -Dxlib-lease=disabled \
            -Degl=enabled \
            -Dgbm=disabled \
            -Dglx=disabled \
            -Dllvm=disabled \
            -Dopengl=true \
            -Dvulkan-drivers= \
            -Dgallium-drivers=zink \
            -Dzstd=disabled \
            -Dglvnd=false \
            -Degl-lib-suffix=_mesa \
            -Dbuildtype=release

meson setup ../../../mesa/ "build-kopper_zink-x86-android" \
            --prefix=$PWD"/../kopper_zink_install_dir/kopper_zink-x86-android" \
            --cross-file "../crossfiles/mesa-crossfile-x86-android" \
            -Dplatforms=android \
            -Dplatform-sdk-version=26 \
            -Dandroid-stub=true \
            -Dxlib-lease=disabled \
            -Degl=enabled \
            -Dgbm=disabled \
            -Dglx=disabled \
            -Dllvm=disabled \
            -Dopengl=true \
            -Dvulkan-drivers= \
            -Dgallium-drivers=zink \
            -Dzstd=disabled \
            -Dglvnd=false \
            -Degl-lib-suffix=_mesa \
            -Dbuildtype=release

meson setup ../../../mesa/ "build-kopper_zink-x86_64-android" \
            --prefix=$PWD"/../kopper_zink_install_dir/kopper_zink-x86_64-android" \
            --cross-file "../crossfiles/mesa-crossfile-x86_64-android" \
            -Dplatforms=android \
            -Dplatform-sdk-version=26 \
            -Dandroid-stub=true \
            -Dxlib-lease=disabled \
            -Degl=enabled \
            -Dgbm=disabled \
            -Dglx=disabled \
            -Dllvm=disabled \
            -Dopengl=true \
            -Dvulkan-drivers= \
            -Dgallium-drivers=zink \
            -Dzstd=disabled \
            -Dglvnd=false \
            -Degl-lib-suffix=_mesa \
            -Dbuildtype=release

ninja -C build-kopper_zink-aarch64-android install
ninja -C build-kopper_zink-armv7a-android install
ninja -C build-kopper_zink-x86-android install
ninja -C build-kopper_zink-x86_64-android install

