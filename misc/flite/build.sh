#!/bin/bash
export SHELLOPTS
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR" || exit 1
cd "flite" || exit 1

export ANDROID_NDK_HOME="${ANDROID_NDK_HOME:-$1}"
if [ -z "$ANDROID_NDK_HOME" ]; then
    echo "Error: ANDROID_NDK_HOME is not set and no argument supplied."
    echo "Usage: $0 <ndk-path> or export ANDROID_NDK_HOME"
    exit 1
fi

ARCHITECTURES=("aarch64" "armv7-a" "x86_64" "x86")
for ARCHITECTURE in "${ARCHITECTURES[@]}"; do
  ./configure --with-langvox=../../minecraft --target=$ARCHITECTURE-android; make -C android
done

