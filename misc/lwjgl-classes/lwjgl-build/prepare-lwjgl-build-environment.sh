#!/bin/bash
# All commands that need downloading go here so it doesn't parallelize
# downloading the files and die
set -e
export LIBFFI_VERSION=3.4.6
export BUILD_FREETYPE_VERSION=2.13.2
export ANDROID=1 LWJGL_BUILD_OFFLINE=1
cd ../lwjgl3 || { echo "lwjgl3 repository not found. did you clone the submodules?"; return 1; }
if [ "$SKIP_LIBFFI" != "1" ]; then
  if [ ! -d libffi ] || [ -z "$(ls -A libffi)" ]; then
    wget https://github.com/libffi/libffi/releases/download/v$LIBFFI_VERSION/libffi-$LIBFFI_VERSION.tar.gz
    tar xvf libffi-$LIBFFI_VERSION.tar.gz
    rm libffi-$LIBFFI_VERSION.tar.gz
    rmdir libffi
    mv libffi-$LIBFFI_VERSION libffi
  fi
fi

if [ "$SKIP_FREETYPE" != "1" ]; then
  if [ ! -d freetype ] || [ -z "$(ls -A freetype)" ]; then
    wget https://downloads.sourceforge.net/project/freetype/freetype2/$BUILD_FREETYPE_VERSION/freetype-$BUILD_FREETYPE_VERSION.tar.gz
    tar xf freetype-$BUILD_FREETYPE_VERSION.tar.gz
    rm freetype-$BUILD_FREETYPE_VERSION.tar.gz
    rmdir freetype
    mv freetype-$BUILD_FREETYPE_VERSION freetype
  fi
fi

# TODO: Remove this jank and compile from source. Then just copy the output of submodules.
ARCHES=("arm64" "arm32" "x86" "x64")
for LWJGL_BUILD_ARCH in "${ARCHES[@]}"; do
    case "$LWJGL_BUILD_ARCH" in
        arm64)
            NDK_ABI=arm64-v8a
            NDK_TARGET=aarch64
            NDK_SUFFIX=""
            ;;
        arm32)
            NDK_ABI=armeabi-v7a
            NDK_TARGET=armv7a
            NDK_SUFFIX=eabi
            ;;
        x86)
            NDK_ABI=x86
            NDK_TARGET=i686
            NDK_SUFFIX=""
            # Workaround: LWJGL 3 lacks x86 Linux libraries
            mkdir -p bin/libs/native/linux/x86/org/lwjgl/{freetype,glfw}
            touch bin/libs/native/linux/x86/org/lwjgl/{freetype/libfreetype.so,glfw/libglfw.so}
            ;;
        x64)
            NDK_ABI=x86_64
            NDK_TARGET=x86_64
            NDK_SUFFIX=""
            ;;
        *)
            echo "Error: Invalid architecture '$LWJGL_BUILD_ARCH'"
            exit 1
            ;;
    esac

    LWJGL_NATIVE=bin/libs/native/linux/$LWJGL_BUILD_ARCH/org/lwjgl
    mkdir -p $LWJGL_NATIVE

    wget -nc "https://github.com/AngelAuraMC/shaderc/releases/latest/download/libshaderc-$NDK_ABI.zip"
    unzip -o libshaderc-$NDK_ABI.zip -d $LWJGL_NATIVE/shaderc
done