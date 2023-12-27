cmake_minimum_required(VERSION 3.23)

set(BUILD_TESTS OFF CACHE BOOL "Build tests")
set(BUILD_BENCHMARK OFF CACHE BOOL "Build benchmark")
set(BUILD_TOOLS OFF CACHE BOOL "Build tools")
set(BUILD_EXAMPLES OFF CACHE BOOL "Build examples")
set(BUILD_ONLY_TESTS OFF CACHE BOOL "Build only tests")
set(WITH_VCPKG OFF CACHE BOOL "Use vcpkg")
set(VCPKG_PATH "" CACHE STRING "Vcpkg path")
set(VCPKG_TARGET_TRIPLET "" CACHE STRING "Vcpkg triplet")

#--------------------------------------------------
set(BUILD_TESTS ON)
set(BUILD_ONLY_CORE ON)
#set(WITH_VCPKG ON)
#set(VCPKG_PATH "/home/ysx/env/vcpkg")
#set(VCPKG_TARGET_TRIPLET "x64-linux")

set(ThridPatryDir ${CMAKE_SOURCE_DIR}/third_party)
set(TianLiCoreDir ${CMAKE_SOURCE_DIR}/Installer/lib_core)

include(cmake/utils.cmake)
include(cmake/version.cmake)
include(cmake/auto_subdirectory.cmake)

tianli_parse_version()
tianli_installer_parse_version(config/version)
message (STATUS "TianLi.Installer version: ${tianli_installer_version_cmake}")

# 统一生成到build目录中的bin和lib中
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

project(TianLi.Installer
        LANGUAGES CXX
        VERSION ${tianli_installer_version_cmake}
        DESCRIPTION "WeiXiTianLi Installer"
        HOMEPAGE_URL "http://www.weixitianli.com/"
)


if (MSVC)
    message(STATUS "MSVC")
else()
    message(STATUS "GCC")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
endif()

# utf-8
if (MSVC)
    add_compile_options(/utf-8)
else()
    add_compile_options(-finput-charset=UTF-8)
    add_compile_options(-fexec-charset=UTF-8)
endif()


if(NOT BUILD_ONLY_TESTS)
    message(STATUS "Build TianLi.Installer")
    add_subdirectory(Installer)
endif()


if (BUILD_TESTS)
    message(STATUS "Build tests")
    add_subdirectory(tests)
endif()

if (BUILD_BENCHMARK)
add_subdirectory(benchmark)
endif()

if (BUILD_TOOLS)
add_subdirectory(tools)
endif()

if (BUILD_EXAMPLES)
add_subdirectory(examples)
endif()
