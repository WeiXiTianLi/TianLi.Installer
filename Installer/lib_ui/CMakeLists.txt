add_library(lib_ui STATIC)
add_library(tianli::lib_ui ALIAS lib_ui)

if(MSVC)
    set_property(TARGET lib_ui PROPERTY  MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

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
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# moc
qt5_wrap_cpp(MOC_SRCS
    tianli_window.h
    tianli_widget.h
    widget/rounded_rectangle.h
    common/time_line_label/time_line_label.h
    )
qt5_wrap_ui(UI_FILES
    tianli_widget.ui
    widget/rounded_rectangle.ui
    common/time_line_label/time_line_label.ui
)
qt5_add_resources(QRC_FILES qrc/tianli.qrc)

target_sources(lib_ui
    PUBLIC
        ${QRC_FILES}
    PRIVATE 
        ${MOC_SRCS} ${UI_FILES}
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
    PUBLIC
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)