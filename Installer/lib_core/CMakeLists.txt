add_library(core STATIC)
add_library(tianli::core ALIAS core)

set(CMAKE_CXX_STANDARD 20)
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET core PROPERTY CXX_STANDARD 20)
endif()

# 设置UTF-8编码
add_definitions(-DUNICODE -D_UNICODE)
# msvc编译器设置utf-8编码
if (MSVC)
    add_compile_options("/utf-8")
    # 设置编译运行时为静态链接
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    #  /NODEFAULTLIB:library
    # if (CMAKE_BUILD_TYPE STREQUAL "Release")
    #     set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /NODEFAULTLIB:MSVCRT")
    # endif()
endif ()

add_subdirectory(core_decompression)
add_subdirectory(core_download)
add_subdirectory(core_install)
add_subdirectory(core_registration)

target_include_directories(core PRIVATE core_decompression)
target_include_directories(core PRIVATE core_download)
target_include_directories(core PRIVATE core_install)
target_include_directories(core PRIVATE core_registration)

target_compile_definitions(core PRIVATE EXPORT_CORE)

target_sources(core
    PUBLIC
        installer.core.h
    PRIVATE
        installer.core.cpp
)

target_link_libraries(core PRIVATE 
    tianli::core::decompression 
    tianli::core::download
    tianli::core::install
    tianli::core::registration)


