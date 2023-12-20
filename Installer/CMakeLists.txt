add_executable(Installer)

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

add_subdirectory(lib_core)
if (NOT BUILD_ONLY_CORE)
    add_subdirectory(lib_ui)
endif()


target_sources(Installer PRIVATE main.cpp resource/resource.rc resource/app_info.rc)
set_target_properties(Installer  PROPERTIES COMPILE_FLAGS "/MT")



target_link_libraries(Installer PRIVATE
        tianli::lib_ui
        #tianli::lib_core
        )