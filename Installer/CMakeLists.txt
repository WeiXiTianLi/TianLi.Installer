add_executable(Installer WIN32 MACOSX_BUNDLE)

add_subdirectory(lib_ui)

target_sources(Installer PRIVATE main.cpp)

target_link_libraries(Installer
        PRIVATE
        tianli::lib_ui
        )