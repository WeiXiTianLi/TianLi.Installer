cmake_minimum_required(VERSION 3.23)

set(ThridPatryDir ${CMAKE_SOURCE_DIR}/third_party)

include(cmake/version.cmake)
tianli_installer_parse_version(config/version)


message (STATUS "TianLi.Installer version: ${tianli_installer_version_cmake}")

project(TianLi.Installer
        LANGUAGES CXX
        VERSION ${tianli_installer_version_cmake}
        DESCRIPTION "WeiXiTianLi Installer"
        HOMEPAGE_URL "http://www.weixitianli.com/"
)

# msvc utf-8
if (MSVC)
    add_compile_options(/utf-8)
endif()

add_subdirectory(Installer)
