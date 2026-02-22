#!/bin/bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR" || exit 1

source check-for-java8.sh
export JAVA8_HOME="${JAVA8_HOME:-$JAVA_HOME}"

usage() {
  local me
  me="$(basename "$0")"
  cat >&2 <<USAGE
Usage: ./$me <os> <abis...>

Arguments:
  os         Target OS. Supported: android, ios
  abis       One or more ABIs (for android only): armeabi-v7a arm64-v8a x86 x86_64

Examples:
  ./$me android armeabi-v7a arm64-v8a x86 x86_64
  ./$me ios

Note: For android, at least one ABI is required.
USAGE
}
_print_usage_on_exit=true
on_exit() {
  local exit_code=$?
  if [ "$exit_code" -ne 0 ] && [ "$_print_usage_on_exit" = true ]; then
    usage
  fi
  exit "$exit_code"
}
trap on_exit EXIT

get_android_arch() {
  case "$1" in
    armeabi-v7a) echo "arm32" ;;
    arm64-v8a)   echo "arm64" ;;
    x86)         echo "x86" ;;
    x86_64)      echo "x64" ;;
    *)
      echo "Unknown Android ABI: $1" >&2
      return 1
      ;;
  esac
}

build_lwjgl() {
  if [ -z "${1+x}" ]; then
    echo "No OS provided" >&2
    return 1
  fi
  local os="$1"
  shift   # remove OS so all remaining args are ABIs
  if [ "$#" -eq 0 ]; then
    echo "No ABIs provided"
    return 1
  fi

  case "$os" in
    android)
      for abi in "$@"; do
        local arch
        arch="$(get_android_arch "$abi")" || return 1
        export LWJGL_BUILD_ARCH="$arch"

        cd ../lwjgl3 || { echo "lwjgl3 repository not found. did you clone the submodules?" >&2; _print_usage_on_exit=false; return 1; }
        echo "Building Android ABI: $abi"
        bash ../lwjgl-build/build-lwjgl-natives-android.sh || return 1
        cd "$SCRIPT_DIR" || return 1

        mkdir -p "build/generated/jniLibs/$abi"
        mkdir -p "build/generated/vulkanmod/jniLibs/$abi"
        mv ../lwjgl3/bin/out/* "build/generated/jniLibs/$abi/"
        mv "build/generated/jniLibs/$abi/libshaderc.so" "build/generated/vulkanmod/jniLibs/$abi/"
        mv "build/generated/jniLibs/$abi/liblwjgl_vma.so" "build/generated/vulkanmod/jniLibs/$abi/"
      done
      ;;

    ios)
      echo "Building iOS ABI: $abi"
      echo "Not yet implemented"
      exit 0
      ;;

    *)
      echo "Unsupported OS: $os" >&2
      return 1
      ;;
  esac
}

build_lwjgl "$@"
