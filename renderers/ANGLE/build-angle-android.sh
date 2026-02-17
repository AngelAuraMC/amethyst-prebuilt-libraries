#!/bin/bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR" || exit 1

cd angle
# Setup depo-tools to clone the dependencies
if [ ! -d "depot_tools" ] ; then
  git clone https://chromium.googlesource.com/chromium/tools/depot_tools.git
fi
export PATH="$PWD/depot_tools:$PATH"
gclient config --spec 'solutions = [
  {
    "name": ".",
    "url": "https://chromium.googlesource.com/angle/angle.git",
    "deps_file": "DEPS",
    "managed": False,
    "custom_vars": {},
  },
]
target_os = ["android"]'
gclient sync -Rf --no-history --with_branch_heads

oses=("android")
arches=("armeabi-v7a" "arm64-v8a" "x86" "x86_64")

for os in "${oses[@]}"; do
  for arch in "${arches[@]}"; do
    build_dir="out/${os}-${arch}"
    
    echo "Generating build files for ${os}-${arch}..."
    gn gen "$build_dir"
    
    echo "Building..."
    autoninja -C "$build_dir"
    
    echo "Copying built natives to ../jniLibs"
    mkdir -p ../build/generated/jniLibs/"${arch}"
    cp "$build_dir"/libGLESv2_angle.so ../build/generated/jniLibs/"${arch}"
    cp "$build_dir"/libEGL_angle.so ../build/generated/jniLibs/"${arch}"
    echo "--------------------------------"

  done
done
