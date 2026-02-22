#!/bin/bash
# This script should be ran when updating lwjgl
# HACK: The release ant task requires using java 8 due to the hacks we use to get lwjglx integrated. This means we can't automatically manage this with AGP.
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR" || exit 1

if [ -z "$LWJGL_BUILD_ARCH" ]; then
    echo "Error: LWJGL_BUILD_ARCH is not set."
    exit 1
fi

check_java8() {
    local var_name=$1
    local java_home=$2

    if [ -z "$java_home" ]; then
        echo "Error: $var_name is not set."
        return 1
    fi

    if [ ! -x "$java_home/bin/java" ]; then
        echo "Error: $var_name ($java_home) does not contain a valid java executable."
        return 1
    fi

    local version=$("$java_home/bin/java" -version 2>&1 | awk -F '"' '/version/ {print $2}')

    if [[ $version == 1.8* ]]; then
        return 0
    else
        echo "Error: $var_name ($java_home) is not Java 8 (found version $version)."
        return 1
    fi
}

check_java8 "JAVA8_HOME" "$JAVA8_HOME" || exit 1
check_java8 "JAVA_HOME" "$JAVA_HOME" || exit 1

# Build the jars
cd lwjgl3 || echo "lwjgl3 folder not found. Did you clone the submodule?" || exit 1
bash ci_build_android.bash
cd .. || echo "lwjgl-classes folder missing. How did this happen?" || exit 1
mkdir -p jre_lwjgl3glfw/libs
mkdir -p jre_lwjgl3glfw/licenses
rm lwjgl3/bin/RELEASE/build.txt

mv -f lwjgl3/bin/RELEASE/**/*.jar jre_lwjgl3glfw/libs || true
mv -f lwjgl3/bin/RELEASE/**/*.txt jre_lwjgl3glfw/licenses || true
mv -f lwjgl3/bin/RELEASE/LICENSE jre_lwjgl3glfw/licenses/lwjgl_license.txt || true


