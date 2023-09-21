add_library(lib_ui STATIC)
add_library(tianli::lib_ui ALIAS lib_ui)


qt5_wrap_ui(UI_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/tianli_widget.ui
        ${CMAKE_CURRENT_SOURCE_DIR}/widget/rounded_rectangle.ui
        ${CMAKE_CURRENT_SOURCE_DIR}/common/time_line_label/time_line_label.ui
)

target_sources(lib_ui
        PRIVATE ${UI_FILES}
        ${CMAKE_CURRENT_SOURCE_DIR}/tianli_widget.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/tianli_widget.h
        ${CMAKE_CURRENT_SOURCE_DIR}/widget/rounded_rectangle.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/widget/rounded_rectangle.h
        ${CMAKE_CURRENT_SOURCE_DIR}/common/time_line_label/time_line_label.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/common/time_line_label/time_line_label.h
        )
        
target_link_libraries(lib_ui
    PRIVATE
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)