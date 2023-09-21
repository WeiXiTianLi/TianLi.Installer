add_executable(Installer)

set(Qt5_DIR "C:/Qt/5.15.7/msvc2019_x64_static/lib/cmake/Qt5")
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
#add_subdirectory(lib_core)
add_subdirectory(lib_ui)

qt5_add_resources(QRC_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/lib_ui/qrc/tianli.qrc
        )

target_sources(Installer PRIVATE main.cpp resource/resource.rc resource/app_info.rc ${QRC_FILES})
set_target_properties(Installer  PROPERTIES COMPILE_FLAGS "/MT")

target_link_libraries(Installer
        PRIVATE
        tianli::lib_ui
        #tianli::lib_core
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )