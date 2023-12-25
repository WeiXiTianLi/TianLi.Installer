add_library(lib_ui STATIC)
add_library(tianli::lib_ui ALIAS lib_ui)


set(Qt5VER "qt-5.15.2-lite-release-static")
set(Qt5_DIR "${ThridPatryDir}/${Qt5VER}/lib/cmake/Qt5")
find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)
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

qt5_add_resources(QRC_FILES  ${CMAKE_CURRENT_SOURCE_DIR}/qrc/tianli.qrc )

target_sources(lib_ui
        PRIVATE ${UI_FILES} ${QRC_FILES}
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