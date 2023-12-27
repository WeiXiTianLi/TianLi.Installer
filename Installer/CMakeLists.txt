

add_subdirectory(lib_core)
if (NOT BUILD_ONLY_CORE)
    add_subdirectory(lib_ui)
endif()

include_directories(lib_core)
if (NOT BUILD_ONLY_CORE)
    include_directories(lib_ui)
endif()

add_executable(Installer)

target_sources(Installer PRIVATE main.cpp resource/resource.rc resource/app_info.rc)

if(MSVC)
    set_property(TARGET Installer PROPERTY  MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

if(BUILD_ONLY_CORE)
    set(libs tianli::core)
else()
    add_compile_definitions(INSTALLER_UI_SUPPORT)
    set(libs tianli::lib_ui tianli::core)
endif()


target_link_libraries(Installer PRIVATE ${libs})
