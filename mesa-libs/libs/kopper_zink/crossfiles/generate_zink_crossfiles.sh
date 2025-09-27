#!/bin/bash
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR" || exit 1

SDK_VER=${SDK_VER:-26}
LIBDRM_INSTALL_DIR=${LIBDRM_INSTALL_DIR:-../libdrm_install_dir}

# Note: The cpu parameter in host_machine doesn't seem to actually do anything.
# Seems like android clang takes care of it.

# AARCH64 ANDROID
LIBDRM_AARCH64_INSTALL_DIR=${LIBDRM_INSTALL_DIR}'/drm-static-aarch64-android'
cat <<EOF > mesa-crossfile-aarch64-android
[binaries]
ndk_root = '$ANDROID_NDK_ROOT'
sdk_ver = '$SDK_VER'
ndk = ndk_root + '/toolchains/llvm/prebuilt/linux-x86_64/bin'
sysroot = ndk_root + '/toolchains/llvm/prebuilt/linux-x86_64/sysroot'
libdrm_install_dir = '$LIBDRM_AARCH64_INSTALL_DIR'
ar = ndk + '/llvm-ar'
c = ['ccache', ndk + '/aarch64-linux-android' + sdk_ver + '-clang', '-O3', '-DVK_USE_PLATFORM_ANDROID_KHR', '-fPIC', '--sysroot=' + sysroot, '-ffunction-sections', '-fdata-sections', '-D_POSIX_SOURCE']
cpp = ['ccache', ndk + '/aarch64-linux-android' + sdk_ver + '-clang++', '-O3', '-DVK_USE_PLATFORM_ANDROID_KHR', '-fPIC', '-fno-exceptions', '-fno-unwind-tables', '-fno-asynchronous-unwind-tables', '-static-libstdc++', '--sysroot=' + sysroot, '-ffunction-sections', '-fdata-sections', '-D_POSIX_SOURCE']
strip = ndk + '/llvm-strip'
pkgconfig = ['env', 'PKG_CONFIG_LIBDIR=' + libdrm_install_dir + '/lib/pkgconfig', 'pkg-config']

[host_machine]
system = 'android'
cpu_family = 'aarch64'
cpu = 'armv8'
endian = 'little'
EOF

# ARM ANDROID
LIBDRM_ARMV7A_INSTALL_DIR=${LIBDRM_INSTALL_DIR}'/drm-static-armv7a-android'
cat <<EOF > mesa-crossfile-armv7a-android
[binaries]
ndk_root = '$ANDROID_NDK_ROOT'
sdk_ver = '$SDK_VER'
ndk = ndk_root + '/toolchains/llvm/prebuilt/linux-x86_64/bin'
sysroot = ndk_root + '/toolchains/llvm/prebuilt/linux-x86_64/sysroot'
libdrm_install_dir = '$LIBDRM_ARMV7A_INSTALL_DIR'
ar = ndk + '/llvm-ar'
c = ['ccache', ndk + '/armv7a-linux-androideabi' + sdk_ver + '-clang', '-O3', '-DVK_USE_PLATFORM_ANDROID_KHR', '-fPIC', '--sysroot=' + sysroot, '-ffunction-sections', '-fdata-sections', '-D_POSIX_SOURCE']
cpp = ['ccache', ndk + '/armv7a-linux-androideabi' + sdk_ver + '-clang++', '-O3', '-DVK_USE_PLATFORM_ANDROID_KHR', '-fPIC', '-fno-exceptions', '-fno-unwind-tables', '-fno-asynchronous-unwind-tables', '-static-libstdc++', '--sysroot=' + sysroot, '-ffunction-sections', '-fdata-sections', '-D_POSIX_SOURCE']
strip = ndk + '/llvm-strip'
pkgconfig = ['env', 'PKG_CONFIG_LIBDIR=' + libdrm_install_dir + '/lib/pkgconfig', 'pkg-config']

[host_machine]
system = 'android'
cpu_family = 'arm'
cpu = 'armv7a'
endian = 'little'
EOF

# X86 ANDROID
LIBDRM_X86_INSTALL_DIR=${LIBDRM_INSTALL_DIR}'/drm-static-x86-android'
cat <<EOF > mesa-crossfile-x86-android
[binaries]
ndk_root = '$ANDROID_NDK_ROOT'
sdk_ver = '$SDK_VER'
ndk = ndk_root + '/toolchains/llvm/prebuilt/linux-x86_64/bin'
sysroot = ndk_root + '/toolchains/llvm/prebuilt/linux-x86_64/sysroot'
libdrm_install_dir = '$LIBDRM_X86_INSTALL_DIR'
ar = ndk + '/llvm-ar'
c = ['ccache', ndk + '/i686-linux-android' + sdk_ver + '-clang', '-O3', '-DVK_USE_PLATFORM_ANDROID_KHR', '-fPIC', '--sysroot=' + sysroot, '-ffunction-sections', '-fdata-sections', '-D_POSIX_SOURCE']
cpp = ['ccache', ndk + '/i686-linux-android' + sdk_ver + '-clang++', '-O3', '-DVK_USE_PLATFORM_ANDROID_KHR', '-fPIC', '-fno-exceptions', '-fno-unwind-tables', '-fno-asynchronous-unwind-tables', '-static-libstdc++', '--sysroot=' + sysroot, '-ffunction-sections', '-fdata-sections', '-D_POSIX_SOURCE']
strip = ndk + '/llvm-strip'
pkgconfig = ['env', 'PKG_CONFIG_LIBDIR=' + libdrm_install_dir + '/lib/pkgconfig', 'pkg-config']

[host_machine]
system = 'android'
cpu_family = 'x86'
cpu = 'i686'
endian = 'little'
EOF

# X86_64 ANDROID
LIBDRM_X86_64_INSTALL_DIR=${LIBDRM_INSTALL_DIR}'/drm-static-x86_64-android'
cat <<EOF > mesa-crossfile-x86_64-android
[binaries]
ndk_root = '$ANDROID_NDK_ROOT'
sdk_ver = '$SDK_VER'
ndk = ndk_root + '/toolchains/llvm/prebuilt/linux-x86_64/bin'
sysroot = ndk_root + '/toolchains/llvm/prebuilt/linux-x86_64/sysroot'
libdrm_install_dir = '$LIBDRM_X86_64_INSTALL_DIR'
ar = ndk + '/llvm-ar'
c = ['ccache', ndk + '/x86_64-linux-android' + sdk_ver + '-clang', '-O3', '-DVK_USE_PLATFORM_ANDROID_KHR', '-fPIC', '--sysroot=' + sysroot, '-ffunction-sections', '-fdata-sections', '-D_POSIX_SOURCE']
cpp = ['ccache', ndk + '/x86_64-linux-android' + sdk_ver + '-clang++', '-O3', '-DVK_USE_PLATFORM_ANDROID_KHR', '-fPIC', '-fno-exceptions', '-fno-unwind-tables', '-fno-asynchronous-unwind-tables', '-static-libstdc++', '--sysroot=' + sysroot, '-ffunction-sections', '-fdata-sections', '-D_POSIX_SOURCE']
strip = ndk + '/llvm-strip'
pkgconfig = ['env', 'PKG_CONFIG_LIBDIR=' + libdrm_install_dir + '/lib/pkgconfig', 'pkg-config']

[host_machine]
system = 'android'
cpu_family = 'x86_64'
cpu = 'x86_64'
endian = 'little'
EOF
