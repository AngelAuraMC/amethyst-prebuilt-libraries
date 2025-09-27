#!/bin/bash
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR" || exit 1

SDK_VER=${SDK_VER:-26}
ANDROID_NDK_ROOT=${ANDROID_NDK_ROOT:-$1}
if [ -z "$ANDROID_NDK_ROOT" ]; then
    echo "Error: NDK path not provided. Set ANDROID_NDK_ROOT or pass as argument."
    exit 1
fi

# AARCH64 ANDROID
cat <<EOF > libdrm-crossfile-aarch64-android
[binaries]
ndk_root = '$ANDROID_NDK_ROOT'
sdk_ver = '$SDK_VER'
ndk = ndk_root + '/toolchains/llvm/prebuilt/linux-x86_64/bin'
sysroot = ndk_root + '/toolchains/llvm/prebuilt/linux-x86_64/sysroot'
ar = ndk + '/llvm-ar'
c = ['ccache', ndk + '/aarch64-linux-android' + sdk_ver + '-clang', '-O3', '-DVK_USE_PLATFORM_ANDROID_KHR', '-fPIC', '--sysroot=' + sysroot]
cpp = ['ccache', ndk + '/aarch64-linux-android' + sdk_ver + '-clang++', '-O3', '-DVK_USE_PLATFORM_ANDROID_KHR', '-fPIC', '-fno-exceptions', '-fno-unwind-tables', '-fno-asynchronous-unwind-tables', '-static-libstdc++', '--sysroot=' + sysroot, '-static', '-ffunction-sections', '-fdata-sections', '-Wl,--gc-sections']
strip = ndk + '/llvm-strip'
pkgconfig = ['pkg-config']

[host_machine]
system = 'android'
cpu_family = 'aarch64'
cpu = 'armv8'
endian = 'little'
EOF

# ARM ANDROID
cat <<EOF > libdrm-crossfile-armv7a-android
[binaries]
ndk_root = '$ANDROID_NDK_ROOT'
sdk_ver = '$SDK_VER'
ndk = ndk_root + '/toolchains/llvm/prebuilt/linux-x86_64/bin'
sysroot = ndk_root + '/toolchains/llvm/prebuilt/linux-x86_64/sysroot'
ar = ndk + '/llvm-ar'
c = ['ccache', ndk + '/armv7a-linux-androideabi' + sdk_ver + '-clang', '-O3', '-DVK_USE_PLATFORM_ANDROID_KHR', '-fPIC', '--sysroot=' + sysroot]
cpp = ['ccache', ndk + '/armv7a-linux-androideabi' + sdk_ver + '-clang++', '-O3', '-DVK_USE_PLATFORM_ANDROID_KHR', '-fPIC', '-fno-exceptions', '-fno-unwind-tables', '-fno-asynchronous-unwind-tables', '-static-libstdc++', '--sysroot=' + sysroot, '-static', '-ffunction-sections', '-fdata-sections', '-Wl,--gc-sections']
strip = ndk + '/llvm-strip'
pkgconfig = ['pkg-config']

[host_machine]
system = 'android'
cpu_family = 'arm'
cpu = 'armv7a'
endian = 'little'
EOF

# X86 ANDROID
cat <<EOF > libdrm-crossfile-x86-android
[binaries]
ndk_root = '$ANDROID_NDK_ROOT'
sdk_ver = '$SDK_VER'
ndk = ndk_root + '/toolchains/llvm/prebuilt/linux-x86_64/bin'
sysroot = ndk_root + '/toolchains/llvm/prebuilt/linux-x86_64/sysroot'
ar = ndk + '/llvm-ar'
c = ['ccache', ndk + '/i686-linux-android' + sdk_ver + '-clang', '-O3', '-DVK_USE_PLATFORM_ANDROID_KHR', '-fPIC', '--sysroot=' + sysroot]
cpp = ['ccache', ndk + '/i686-linux-android' + sdk_ver + '-clang++', '-O3', '-DVK_USE_PLATFORM_ANDROID_KHR', '-fPIC', '-fno-exceptions', '-fno-unwind-tables', '-fno-asynchronous-unwind-tables', '-static-libstdc++', '--sysroot=' + sysroot, '-static', '-ffunction-sections', '-fdata-sections', '-Wl,--gc-sections']
strip = ndk + '/llvm-strip'
pkgconfig = ['pkg-config']

[host_machine]
system = 'android'
cpu_family = 'x86'
cpu = 'i686'
endian = 'little'
EOF

# X86_64 ANDROID
cat <<EOF > libdrm-crossfile-x86_64-android
[binaries]
ndk_root = '$ANDROID_NDK_ROOT'
sdk_ver = '$SDK_VER'
ndk = ndk_root + '/toolchains/llvm/prebuilt/linux-x86_64/bin'
sysroot = ndk_root + '/toolchains/llvm/prebuilt/linux-x86_64/sysroot'
ar = ndk + '/llvm-ar'
c = ['ccache', ndk + '/x86_64-linux-android' + sdk_ver + '-clang', '-O3', '-DVK_USE_PLATFORM_ANDROID_KHR', '-fPIC', '--sysroot=' + sysroot]
cpp = ['ccache', ndk + '/x86_64-linux-android' + sdk_ver + '-clang++', '-O3', '-DVK_USE_PLATFORM_ANDROID_KHR', '-fPIC', '-fno-exceptions', '-fno-unwind-tables', '-fno-asynchronous-unwind-tables', '-static-libstdc++', '--sysroot=' + sysroot, '-static', '-ffunction-sections', '-fdata-sections', '-Wl,--gc-sections']
strip = ndk + '/llvm-strip'
pkgconfig = ['pkg-config']

[host_machine]
system = 'android'
cpu_family = 'x86_64'
cpu = 'x86_64'
endian = 'little'
EOF
