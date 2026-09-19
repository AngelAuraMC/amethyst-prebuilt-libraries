cmake_minimum_required(VERSION 3.5)
project(sqlitejdbc C)

# Builds Distant Horizons-compatible libsqlitejdbc.so from the xerial/sqlite-jdbc
# submodule (pinned at 94c0ea1 = 3.53.2.1).
#
# The amalgamation download/patching and the dh_sqlite rename happen in the
# prepareSqliteAmalgamation Gradle task (see build.gradle), which the configureCMake
# tasks depend on. This file only compiles the prepared sources in build/sqlite-gen:
#   - sqlite3.c / sqlite3.h: patched amalgamation (RegisterExtensionFunctions,
#     "JDBC_EXTENSIONS" compile option, appended extension-functions.c)
#   - NativeDB.c: submodule NativeDB.c renamed like DH's NativeRelocator does
#     (org_sqlite -> dh_1sqlite, org/sqlite -> dh_sqlite), matching the JNI symbols
#     of dh_sqlite.core.NativeDB inside the Distant Horizons jar

set(GEN_DIR "${CMAKE_CURRENT_SOURCE_DIR}/build/sqlite-gen")
# native-src/NativeDB.h: javac -h generated from the same commit, renamed the same way,
# vendored (javac needs slf4j-api, so it is not generated at build time).
set(NATIVE_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/native-src")

add_library(sqlitejdbc SHARED
        "${GEN_DIR}/sqlite3.c"
        "${GEN_DIR}/NativeDB.c")

target_include_directories(sqlitejdbc PRIVATE
        "${NATIVE_SRC_DIR}"
        "${GEN_DIR}")

target_compile_definitions(sqlitejdbc PRIVATE
        SQLITE_ENABLE_LOAD_EXTENSION=1
        SQLITE_HAVE_ISNAN
        HAVE_USLEEP=1
        SQLITE_ENABLE_COLUMN_METADATA
        SQLITE_CORE
        SQLITE_ENABLE_FTS3
        SQLITE_ENABLE_FTS3_PARENTHESIS
        SQLITE_ENABLE_FTS5
        SQLITE_ENABLE_RTREE
        SQLITE_ENABLE_PERCENTILE
        SQLITE_ENABLE_STAT4
        SQLITE_ENABLE_DBSTAT_VTAB
        SQLITE_ENABLE_MATH_FUNCTIONS
        SQLITE_THREADSAFE=1
        SQLITE_DEFAULT_MEMSTATUS=0
        SQLITE_DEFAULT_FILE_PERMISSIONS=0666
        SQLITE_MAX_VARIABLE_NUMBER=250000
        SQLITE_MAX_MMAP_SIZE=1099511627776
        SQLITE_MAX_LENGTH=2147483647
        SQLITE_MAX_COLUMN=32767
        SQLITE_MAX_SQL_LENGTH=1073741824
        SQLITE_MAX_FUNCTION_ARG=127
        SQLITE_MAX_ATTACHED=125
        SQLITE_MAX_PAGE_COUNT=4294967294
        SQLITE_DISABLE_PAGECACHE_OVERFLOW_STATS
        SQLITE_ENABLE_UPDATE_DELETE_LIMIT)

target_compile_options(sqlitejdbc PRIVATE
        -fvisibility=hidden
        -Wno-implicit-function-declaration
        -Oz)

target_link_libraries(sqlitejdbc PRIVATE log android)
target_link_options(sqlitejdbc PRIVATE -Wl,-z,max-page-size=16384)
