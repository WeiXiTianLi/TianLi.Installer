add_executable(Installer WIN32 MACOSX_BUNDLE)
# 静态链接Qt
if(MSVC)
    set_property(TARGET Installer PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()


set(Qt5_DIR "E:/Qt/5.15.7/msvc2019_64_static/lib/cmake/Qt5")
find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)
set(CMAKE_PREFIX_PATH {Qt5_DIR})
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

add_subdirectory(lib_ui)

qt5_add_resources(QRC_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/lib_ui/qrc/tianli.qrc
        )

target_sources(Installer PRIVATE main.cpp resource/resource.rc resource/app_info.rc ${QRC_FILES})

target_link_libraries(Installer
        PRIVATE
        tianli::lib_ui
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )