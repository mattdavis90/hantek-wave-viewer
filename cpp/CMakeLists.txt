cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

# Main executable
project(HantekWavefile VERSION 0.1.1)

set(BINARY "hantek")
set(SRC "${PROJECT_SOURCE_DIR}/src")
set(INC "${PROJECT_SOURCE_DIR}/inc")

file(GLOB all_INCS
    "${INC}/*.hpp"
    "${INC}/*.h"
)
file(GLOB all_SRCS
    "${SRC}/*.cpp"
)
add_executable(${BINARY} ${all_SRCS} ${all_INCS})
include_directories(${SRC})
target_include_directories(${BINARY} PRIVATE ${INC})
set_property(TARGET ${BINARY} PROPERTY CXX_STANDARD 17)
target_compile_definitions(${BINARY} PUBLIC DOCTEST_CONFIG_DISABLE)

# Enable optimised builds
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Test Executable
set(TEST_BINARY "hantek_test")
list(REMOVE_ITEM all_SRCS "${SRC}/main.cpp")
add_executable(${TEST_BINARY} ${all_SRCS} ${all_INCS} "${PROJECT_SOURCE_DIR}/test/main.cpp")
target_include_directories(${TEST_BINARY} PRIVATE ${INC})
set_property(TARGET ${TEST_BINARY} PROPERTY CXX_STANDARD 17)

# CPM to manage deps
include(cmake/CPM.cmake)

# Add Kaitai Struct and link
CPMAddPackage(
  NAME kaitai_struct_cpp_stl_runtime
  GITHUB_REPOSITORY kaitai-io/kaitai_struct_cpp_stl_runtime
  GIT_TAG 0.10.1
  VERSION 0.10.0
  OPTIONS "BUILD_TESTS OFF"
)
CPMAddPackage("gh:p-ranav/argparse@3.0")
CPMAddPackage("gh:agauniyal/rang@3.2")
CPMAddPackage("gh:fmtlib/fmt#10.2.1")
CPMAddPackage("gh:/doctest/doctest@2.4.11")
target_link_libraries(${BINARY} kaitai_struct_cpp_stl_runtime argparse rang fmt doctest)
target_link_libraries(${TEST_BINARY} kaitai_struct_cpp_stl_runtime argparse rang fmt doctest)

# Store the version number in "src/version.cpp"
set(VERSION "const char* VERSION=\"${CMAKE_PROJECT_VERSION}\";")
set(VERSION_FILE "${SRC}/version.cpp")
if(EXISTS ${VERSION_FILE})
    file(READ ${VERSION_FILE} VERSION_)
else()
    set(VERSION_ "")
endif()
if (NOT "${VERSION}" STREQUAL "${VERSION_}")
    file(WRITE ${VERSION_FILE} "${VERSION}")
endif()
