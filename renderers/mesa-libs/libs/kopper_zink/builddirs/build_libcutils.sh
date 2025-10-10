#!/bin/bash
set -euo pipefail
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR" || exit 1

fetch_android_file() {
  # Usage: fetch_android_file <repo_path> <branch> <file_path> <out_path>
  local repo_path="$1"
  local branch="$2"
  local file_path="$3"
  local out_path="$4"
  local max_retries=6
  local attempt=1
  local success=0

  if [[ -z "$repo_path" || -z "$branch" || -z "$file_path" || -z "$out_path" ]]; then
    echo "Usage: fetch_android_file <repo_path> <branch> <file_path> <out_path>"
    return 1
  fi

  if [[ -f "$out_path" ]]; then
    echo "Skipping $out_path — file already exists."
    return 0
  fi

  mkdir -p "$(dirname "$out_path")"
  local url="https://android.googlesource.com/${repo_path}/+/${branch}/${file_path}?format=TEXT"

  while [[ $attempt -le $max_retries ]]; do
    echo "Fetching (attempt $attempt): $file_path"
    if curl -s "$url" | base64 --decode > "$out_path"; then
      echo "Saved to $out_path"
      success=1
      break
    else
      echo "Failed to fetch $file_path. Retrying in 2 seconds..."
      sleep 2
      ((attempt++))
    fi
  done

  if [[ $success -eq 0 ]]; then
    echo "Failed to fetch $file_path after $max_retries attempts."
    return 1
  fi
}

mkdir $PWD/libcutils-build-universal || true
cd $PWD/libcutils-build-universal
# Source files
fetch_android_file platform/system/core refs/tags/android-platform-13.0.0_r34 libcutils/trace-dev.inc trace-dev.inc
fetch_android_file platform/system/core refs/tags/android-platform-13.0.0_r34 libcutils/trace-dev.cpp trace-dev.cpp
fetch_android_file platform/system/core refs/tags/android-platform-13.0.0_r34 libcutils/properties.cpp properties.cpp

# android-base includes
fetch_android_file platform/system/libbase refs/tags/android-platform-13.0.0_r34 include/android-base/properties.h ./include/android-base/properties.h

# cutils includes
fetch_android_file platform/system/core refs/tags/android-platform-13.0.0_r34 libcutils/include/cutils/android_get_control_file.h ./include/cutils/android_get_control_file.h
fetch_android_file platform/system/core refs/tags/android-platform-13.0.0_r34 libcutils/include/private/android_filesystem_config.h ./include/private/android_filesystem_config.h
ln -s ../private/android_filesystem_config.h include/cutils || true # This is weird but thats how android did it so
fetch_android_file platform/system/core refs/tags/android-platform-13.0.0_r34 libcutils/include/cutils/android_reboot.h ./include/cutils/android_reboot.h
fetch_android_file platform/system/core refs/tags/android-platform-13.0.0_r34 libcutils/include/cutils/ashmem.h ./include/cutils/ashmem.h
fetch_android_file platform/system/core refs/tags/android-platform-13.0.0_r34 libcutils/include/cutils/atomic.h ./include/cutils/atomic.h
fetch_android_file platform/system/core refs/tags/android-platform-13.0.0_r34 libcutils/include/cutils/bitops.h ./include/cutils/bitops.h
fetch_android_file platform/system/core refs/tags/android-platform-13.0.0_r34 libcutils/include/cutils/compiler.h ./include/cutils/compiler.h
fetch_android_file platform/system/core refs/tags/android-platform-13.0.0_r34 libcutils/include/cutils/config_utils.h ./include/cutils/config_utils.h
fetch_android_file platform/system/core refs/tags/android-platform-13.0.0_r34 libcutils/include/cutils/fs.h ./include/cutils/fs.h
fetch_android_file platform/system/core refs/tags/android-platform-13.0.0_r34 libcutils/include/cutils/hashmap.h ./include/cutils/hashmap.h
fetch_android_file platform/system/core refs/tags/android-platform-13.0.0_r34 libcutils/include/cutils/iosched_policy.h ./include/cutils/iosched_policy.h
fetch_android_file platform/system/core refs/tags/android-platform-13.0.0_r34 libcutils/include/cutils/klog.h ./include/cutils/klog.h
fetch_android_file platform/system/core refs/tags/android-platform-13.0.0_r34 libcutils/include/cutils/list.h ./include/cutils/list.h
fetch_android_file platform/system/core refs/tags/android-platform-13.0.0_r34 libcutils/include/cutils/log.h ./include/cutils/log.h
fetch_android_file platform/system/core refs/tags/android-platform-13.0.0_r34 libcutils/include/cutils/memory.h ./include/cutils/memory.h
fetch_android_file platform/system/core refs/tags/android-platform-13.0.0_r34 libcutils/include/cutils/misc.h ./include/cutils/misc.h
fetch_android_file platform/system/core refs/tags/android-platform-13.0.0_r34 libcutils/include/cutils/multiuser.h ./include/cutils/multiuser.h
fetch_android_file platform/system/core refs/tags/android-platform-13.0.0_r34 libcutils/include/cutils/native_handle.h ./include/cutils/native_handle.h
fetch_android_file platform/system/core refs/tags/android-platform-13.0.0_r34 libcutils/include/cutils/partition_utils.h ./include/cutils/partition_utils.h
fetch_android_file platform/system/core refs/tags/android-platform-13.0.0_r34 libcutils/include/cutils/properties.h ./include/cutils/properties.h
fetch_android_file platform/system/core refs/tags/android-platform-13.0.0_r34 libcutils/include/cutils/qtaguid.h ./include/cutils/qtaguid.h
fetch_android_file platform/system/core refs/tags/android-platform-13.0.0_r34 libcutils/include/cutils/record_stream.h ./include/cutils/record_stream.h
fetch_android_file platform/system/core refs/tags/android-platform-13.0.0_r34 libcutils/include/cutils/sched_policy.h ./include/cutils/sched_policy.h
fetch_android_file platform/system/core refs/tags/android-platform-13.0.0_r34 libcutils/include/cutils/sockets.h ./include/cutils/sockets.h
fetch_android_file platform/system/core refs/tags/android-platform-13.0.0_r34 libcutils/include/cutils/str_parms.h ./include/cutils/str_parms.h
fetch_android_file platform/system/core refs/tags/android-platform-13.0.0_r34 libcutils/include/cutils/trace.h ./include/cutils/trace.h
fetch_android_file platform/system/core refs/tags/android-platform-13.0.0_r34 libcutils/include/cutils/uevent.h ./include/cutils/uevent.h

# liblog includes
fetch_android_file platform/system/logging refs/tags/android-platform-13.0.0_r34 liblog/include/log/event_tag_map.h ./include/log/event_tag_map.h
fetch_android_file platform/system/logging refs/tags/android-platform-13.0.0_r34 liblog/include/log/log_event_list.h ./include/log/log_event_list.h
fetch_android_file platform/system/logging refs/tags/android-platform-13.0.0_r34 liblog/include/log/log.h ./include/log/log.h
fetch_android_file platform/system/logging refs/tags/android-platform-13.0.0_r34 liblog/include/log/log_id.h ./include/log/log_id.h
fetch_android_file platform/system/logging refs/tags/android-platform-13.0.0_r34 liblog/include/log/log_main.h ./include/log/log_main.h
fetch_android_file platform/system/logging refs/tags/android-platform-13.0.0_r34 liblog/include/log/logprint.h ./include/log/logprint.h
fetch_android_file platform/system/logging refs/tags/android-platform-13.0.0_r34 liblog/include/log/log_properties.h ./include/log/log_properties.h
fetch_android_file platform/system/logging refs/tags/android-platform-13.0.0_r34 liblog/include/log/log_radio.h ./include/log/log_radio.h
fetch_android_file platform/system/logging refs/tags/android-platform-13.0.0_r34 liblog/include/log/log_read.h ./include/log/log_read.h
fetch_android_file platform/system/logging refs/tags/android-platform-13.0.0_r34 liblog/include/log/log_safetynet.h ./include/log/log_safetynet.h
fetch_android_file platform/system/logging refs/tags/android-platform-13.0.0_r34 liblog/include/log/log_system.h ./include/log/log_system.h
fetch_android_file platform/system/logging refs/tags/android-platform-13.0.0_r34 liblog/include/log/log_time.h ./include/log/log_time.h

echo "Creating shared library (aarch64)"
$ANDROID_NDK_ROOT/toolchains/llvm/prebuilt/linux-x86_64/bin/aarch64-linux-android26-clang++ -I ./include/ -I $ANDROID_NDK_ROOT/sources/third_party/googletest/include/ -I $ANDROID_NDK_ROOT/toolchains/llvm/prebuilt/linux-x86_64/sysroot/usr/include/ --shared -std=c++17 -fPIC trace-dev.cpp properties.cpp -o ../../jniLibs/arm64-v8a/libcutils.so -llog
echo "Creating shared library (armeabi-v7a)"
$ANDROID_NDK_ROOT/toolchains/llvm/prebuilt/linux-x86_64/bin/armv7a-linux-androideabi26-clang++ -I ./include/ -I $ANDROID_NDK_ROOT/sources/third_party/googletest/include/ -I $ANDROID_NDK_ROOT/toolchains/llvm/prebuilt/linux-x86_64/sysroot/usr/include/ --shared -std=c++17 -fPIC trace-dev.cpp properties.cpp -o ../../jniLibs/armeabi-v7a/libcutils.so -llog
echo "Creating shared library (x86_64)"
$ANDROID_NDK_ROOT/toolchains/llvm/prebuilt/linux-x86_64/bin/x86_64-linux-android26-clang++ -I ./include/ -I $ANDROID_NDK_ROOT/sources/third_party/googletest/include/ -I $ANDROID_NDK_ROOT/toolchains/llvm/prebuilt/linux-x86_64/sysroot/usr/include/ --shared -std=c++17 -fPIC trace-dev.cpp properties.cpp -o ../../jniLibs/x86_64/libcutils.so -llog
echo "Creating shared library (x86)"
$ANDROID_NDK_ROOT/toolchains/llvm/prebuilt/linux-x86_64/bin/i686-linux-android26-clang++ -I ./include/ -I $ANDROID_NDK_ROOT/sources/third_party/googletest/include/ -I $ANDROID_NDK_ROOT/toolchains/llvm/prebuilt/linux-x86_64/sysroot/usr/include/ --shared -std=c++17 -fPIC trace-dev.cpp properties.cpp -o ../../jniLibs/x86/libcutils.so -llog

