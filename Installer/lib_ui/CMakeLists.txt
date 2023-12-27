add_library(lib_ui STATIC)
add_library(tianli::lib_ui ALIAS lib_ui)

if(MSVC)
    set(Qt5VER "qt-5.15.2-lite-release-static")
    set(Qt5_DIR "${ThridPatryDir}/${Qt5VER}/lib/cmake/Qt5")
else()
    if(WITH_VCPKG)
        message(STATUS "Use vcpkg")
        if (NOT VCPKG_PATH)
                message(FATAL_ERROR "VCPKG_PATH is empty")
        endif()
        if (NOT VCPKG_TARGET_TRIPLET)
                message(FATAL_ERROR "VCPKG_TARGET_TRIPLET is empty")
        endif()
        set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${VCPKG_PATH}/installed/${VCPKG_TARGET_TRIPLET})
    endif()
endif()

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

target_sources(lib_ui
    PRIVATE
        tianli_widget.cpp
        tianli_widget.h
        tianli_window.cpp
        tianli_window.h
        widget/rounded_rectangle.cpp
        widget/rounded_rectangle.h
        common/time_line_label/time_line_label.cpp
        common/time_line_label/time_line_label.h
        )
        
target_link_libraries(lib_ui
    PRIVATE
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)