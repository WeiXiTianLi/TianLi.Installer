cmake_minimum_required(VERSION 3.23)

set(ThridPatryDir ${CMAKE_SOURCE_DIR}/third_party)

include(cmake/version.cmake)
include(cmake/auto_subdirectory.cmake)

tianli_installer_parse_version(config/version)
message (STATUS "TianLi.Installer version: ${tianli_installer_version_cmake}")

project(TianLi.Installer
        LANGUAGES CXX
        VERSION ${tianli_installer_version_cmake}
        DESCRIPTION "WeiXiTianLi Installer"
        HOMEPAGE_URL "http://www.weixitianli.com/"
)

set(BUILD_ONLY_TESTS OFF CACHE BOOL "Build only tests")
set(BUILD_ONLY_TESTS ON)

# utf-8
if (MSVC)
    add_compile_options(/utf-8)
else()
    add_compile_options(-finput-charset=UTF-8)
    add_compile_options(-fexec-charset=UTF-8)
endif()


if(NOT BUILD_ONLY_TESTS)
    add_subdirectory(Installer)
endif()
add_subdirectory(tools)
add_subdirectory(tests)
