

add_subdirectory(lib_core)
if (NOT BUILD_ONLY_CORE)
    add_subdirectory(lib_ui)
endif()


add_executable(Installer)

target_sources(Installer PRIVATE main.cpp resource/resource.rc resource/app_info.rc)

if(MSVC)
    set_property(TARGET Installer PROPERTY  MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
else()
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -static")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -static")
endif()

if(BUILD_ONLY_CORE)
    set(libs tianli::core)
else()
    add_compile_definitions(INSTALLER_UI_SUPPORT)
    set(libs tianli::lib_ui tianli::core)
endif()


target_link_libraries(Installer PRIVATE ${libs})
