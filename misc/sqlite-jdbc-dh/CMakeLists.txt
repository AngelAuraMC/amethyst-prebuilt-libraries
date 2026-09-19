cmake_minimum_required(VERSION 3.5)
project(sqlitejdbc C)

# Builds Distant Horizons-compatible libsqlitejdbc.so from the xerial/sqlite-jdbc
# submodule (pinned at 94c0ea1 = 3.53.2.1), replicating upstream's Makefile:
#   - fetch the SQLite amalgamation (3.53.2)
#   - insert RegisterExtensionFunctions() into openDatabase()
#   - register the "JDBC_EXTENSIONS" compile option
#   - append src/main/ext/extension-functions.c to the amalgamation
#   - compile with upstream's SQLITE_* option set
# and Distant Horizons' NativeRelocator rename applied at source level:
#   org_sqlite -> dh_1sqlite   (JNI symbols Java_dh_1sqlite_core_NativeDB_*)
#   org/sqlite -> dh_sqlite    (FindClass strings, dh_sqlite.core.NativeDB)

set(SUBMODULE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/sqlite-jdbc")
# Shared across all ABIs (CMAKE_BINARY_DIR is per-ABI under .cxx/, which would
# download and patch the amalgamation once per ABI). Lives under build/ so it is
# gitignored and wiped by clean.
set(GEN_DIR "${CMAKE_CURRENT_SOURCE_DIR}/build/sqlite-gen")
file(MAKE_DIRECTORY "${GEN_DIR}")

# --- Resolve the SQLite version from the submodule's VERSION file -------------
file(STRINGS "${SUBMODULE_DIR}/VERSION" VERSION_LINE)
string(REGEX REPLACE "^version=" "" SQLITE_VER "${VERSION_LINE}")
string(REGEX MATCHALL "[0-9]+" SQLITE_VER_PARTS "${SQLITE_VER}")
list(GET SQLITE_VER_PARTS 0 SQLITE_VER_MAJOR)
list(GET SQLITE_VER_PARTS 1 SQLITE_VER_MINOR)
list(GET SQLITE_VER_PARTS 2 SQLITE_VER_PATCH)
# 3.53.2 -> 3530200 (X + 2-digit Y + 2-digit Z + "00"), same as sqlite.org URLs
string(REGEX REPLACE "^([0-9])$" "0\\1" SQLITE_VER_MINOR "${SQLITE_VER_MINOR}")
string(REGEX REPLACE "^([0-9])$" "0\\1" SQLITE_VER_PATCH "${SQLITE_VER_PATCH}")
set(SQLITE_AMAL_PREFIX "sqlite-amalgamation-${SQLITE_VER_MAJOR}${SQLITE_VER_MINOR}${SQLITE_VER_PATCH}00")

# --- Download + unpack the amalgamation ---------------------------------------
# 3.53.2 was published under https://www.sqlite.org/2026/
set(SQLITE_AMAL_ZIP "${GEN_DIR}/${SQLITE_AMAL_PREFIX}.zip")
set(SQLITE_AMAL_DIR "${GEN_DIR}/${SQLITE_AMAL_PREFIX}")
if (NOT EXISTS "${SQLITE_AMAL_DIR}/sqlite3.c")
    if (NOT EXISTS "${SQLITE_AMAL_ZIP}")
        message(STATUS "Downloading ${SQLITE_AMAL_PREFIX} from sqlite.org ...")
        file(DOWNLOAD
                "https://www.sqlite.org/2026/${SQLITE_AMAL_PREFIX}.zip"
                "${SQLITE_AMAL_ZIP}"
                SHOW_PROGRESS
                STATUS SQLITE_DL_STATUS)
        list(GET SQLITE_DL_STATUS 0 SQLITE_DL_CODE)
        if (NOT SQLITE_DL_CODE EQUAL 0)
            message(FATAL_ERROR "Failed to download ${SQLITE_AMAL_PREFIX}.zip: ${SQLITE_DL_STATUS}")
        endif ()
    endif ()
    # file(ARCHIVE_EXTRACT) is broken in the cmake 3.22.1 build shipped by the
    # Android SDK, so extract through the portable cmake -E tar frontend instead.
    execute_process(COMMAND "${CMAKE_COMMAND}" -E tar xf "${SQLITE_AMAL_ZIP}"
            WORKING_DIRECTORY "${GEN_DIR}"
            RESULT_VARIABLE SQLITE_EXTRACT_RESULT)
    if (NOT SQLITE_EXTRACT_RESULT EQUAL 0)
        message(FATAL_ERROR "Failed to extract ${SQLITE_AMAL_PREFIX}.zip: ${SQLITE_EXTRACT_RESULT}")
    endif ()
endif ()

# --- Patch the amalgamation (upstream Makefile's perl steps) -------------------
file(READ "${SQLITE_AMAL_DIR}/sqlite3.c" SQLITE3_C)

# insert a code for loading extension functions
string(REPLACE "opendb_out:"
        "  if(!db->mallocFailed && rc==SQLITE_OK){ rc = RegisterExtensionFunctions(db); }\nopendb_out:"
        SQLITE3_C "${SQLITE3_C}")

# register compile option 'JDBC_EXTENSIONS'
string(REPLACE "static const char * const sqlite3azCompileOpt[] = {"
        "static const char * const sqlite3azCompileOpt[] = {\n\n/* This has been automatically added by sqlite-jdbc */\n  \"JDBC_EXTENSIONS\","
        SQLITE3_C "${SQLITE3_C}")

file(WRITE "${GEN_DIR}/sqlite3.c" "${SQLITE3_C}")
configure_file("${SQLITE_AMAL_DIR}/sqlite3.h" "${GEN_DIR}/sqlite3.h" COPYONLY)

# append the JDBC extension functions to the amalgamation
file(READ "${SUBMODULE_DIR}/src/main/ext/extension-functions.c" EXT_FUNCTIONS_C)
file(APPEND "${GEN_DIR}/sqlite3.c" "${EXT_FUNCTIONS_C}")

# --- Rename NativeDB.c for Distant Horizons (dh_sqlite.core.NativeDB) ---------
file(READ "${SUBMODULE_DIR}/src/main/java/org/sqlite/core/NativeDB.c" NATIVEDB_C)
string(REPLACE "org_sqlite" "dh_1sqlite" NATIVEDB_C "${NATIVEDB_C}")
string(REPLACE "org/sqlite" "dh_sqlite" NATIVEDB_C "${NATIVEDB_C}")
string(REPLACE "org.sqlite" "dh_sqlite" NATIVEDB_C "${NATIVEDB_C}")
file(WRITE "${GEN_DIR}/NativeDB.c" "${NATIVEDB_C}")

# NativeDB.h: javac -h generated from the same commit, renamed the same way,
# vendored in native-src/ (javac needs slf4j-api, so it is not generated at build time).
add_library(sqlitejdbc SHARED
        "${GEN_DIR}/sqlite3.c"
        "${GEN_DIR}/NativeDB.c")

target_include_directories(sqlitejdbc PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/native-src"
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
