add_library(lib_ui STATIC ${CMAKE_CURRENT_SOURCE_DIR}/qrc/tianli.qrc)
add_library(tianli::lib_ui ALIAS lib_ui)
if(MSVC)
    set_property(TARGET lib_ui PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

set(Qt5_DIR "E:/Qt/5.15.7/msvc2019_64_static/lib/cmake/Qt5")
find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)
target_link_libraries(lib_ui
    PRIVATE
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)
set(CMAKE_PREFIX_PATH {Qt5_DIR})
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

qt5_wrap_ui(UI_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/tianli_widget.ui
        ${CMAKE_CURRENT_SOURCE_DIR}/widget/rounded_rectangle.ui
        ${CMAKE_CURRENT_SOURCE_DIR}/common/time_line_label/time_line_label.ui
)
qt5_add_resources(QRC_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/qrc/tianli.qrc
        #${CMAKE_CURRENT_SOURCE_DIR}/tianli_widget.qrc
        #${CMAKE_CURRENT_SOURCE_DIR}/widget/rounded_rectangle.qrc
        #${CMAKE_CURRENT_SOURCE_DIR}/common/time_line_label/time_line_label.qrc
)

SOURCE_GROUP("Resource Files" FILES ${QRC_FILES})

target_sources(lib_ui
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/qrc/tianli.qrc

        ${CMAKE_CURRENT_SOURCE_DIR}/tianli_widget.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/tianli_widget.h
        ${CMAKE_CURRENT_SOURCE_DIR}/widget/rounded_rectangle.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/widget/rounded_rectangle.h
        ${CMAKE_CURRENT_SOURCE_DIR}/common/time_line_label/time_line_label.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/common/time_line_label/time_line_label.h
        )