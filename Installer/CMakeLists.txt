add_executable(Installer)

set(Qt5VER "qt-5.15.2-lite-release-static")
set(Qt5_DIR "${ThridPatryDir}/${Qt5VER}/lib/cmake/Qt5")
find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)
set(CMAKE_PREFIX_PATH {Qt5_DIR})
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

# mt
if(MSVC)
    # static link
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
else()
    # static link
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -static")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -static")
endif()
#
add_subdirectory(lib_core)
add_subdirectory(lib_ui)

qt5_add_resources(QRC_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/lib_ui/qrc/tianli.qrc
        )

target_sources(Installer PRIVATE main.cpp resource/resource.rc resource/app_info.rc ${QRC_FILES})
set_target_properties(Installer  PROPERTIES COMPILE_FLAGS "/MT")


# cpr
#include(FetchContent)
#FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
#                         GIT_TAG 1.10.4) 
#FetchContent_MakeAvailable(cpr)
## spdlog
#FetchContent_Declare(spdlog GIT_REPOSITORY https://github.com/gabime/spdlog.git
#                            GIT_TAG v1.12.0) 
#FetchContent_MakeAvailable(spdlog)

# qt
target_link_libraries(Installer PRIVATE Qt5::Core Qt5::Gui Qt5::Widgets)
# cpr
#target_link_libraries(Installer PRIVATE cpr::cpr)
# spdlog
#target_link_libraries(Installer PRIVATE spdlog::spdlog spdlog::spdlog_header_only)

target_link_libraries(Installer PRIVATE
        tianli::lib_ui
        #tianli::lib_core
        )
# set_target_properties(Installer  PROPERTIES 
#         OUTPUT_NAME "维系天理-安装器" SUFFIX ".exe")