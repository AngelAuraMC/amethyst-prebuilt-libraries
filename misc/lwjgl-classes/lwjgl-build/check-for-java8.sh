#!/bin/bash
if [ -n "${JAVA8_HOME:-}" ]; then
  return 0
fi

if [ -z "$JAVA_HOME" ]; then
  echo "ERROR: JAVA_HOME is not set."
  exit 1
fi

JAVA_VERSION=$("$JAVA_HOME/bin/java" -version 2>&1 | head -n 1)

if [[ "$JAVA_VERSION" != *"1.8."* ]]; then
  echo "ERROR: JAVA_HOME and JAVA8_HOME do not point to Java 8 installation"
  echo "Detected: $JAVA_VERSION"
  exit 1
fi
