cmake_minimum_required(VERSION 3.23)

include(cmake/version.cmake)
tianli_installer_parse_version(config/version)

set(CMAKE_TOOLCHAIN_FILE "E:/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")

project(TianLi.Installer
        LANGUAGES CXX
        VERSION ${tianli_installer_version_cmake}
        DESCRIPTION "WeiXiTianLi Installer"
        HOMEPAGE_URL "http://www.weixitianli.com/"
)

add_subdirectory(Installer)
