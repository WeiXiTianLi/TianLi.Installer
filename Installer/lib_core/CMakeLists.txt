add_library(lib_core STATIC)
add_library(tianli::lib_core ALIAS lib_core)


set(BUILD_SHARED_LIBS OFF)


# 设置为C++17
set(CMAKE_CXX_STANDARD 20)
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET lib_core PROPERTY CXX_STANDARD 20)
endif()

# 设置UTF-8编码
add_definitions(-DUNICODE -D_UNICODE)
# msvc编译器设置utf-8编码
if (MSVC)
    add_compile_options("/utf-8")
    # 设置编译运行时为静态链接
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif ()


add_subdirectory(core_decompression)
add_subdirectory(core_download)

#include(FetchContent)
## cpr
#FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/GengGode/cpr
#    GIT_TAG master)
#FetchContent_MakeAvailable(cpr)
#target_link_libraries(lib_core PRIVATE cpr::cpr)
## zlib
#FetchContent_Declare(zlib GIT_REPOSITORY https://github.com/madler/zlib
#    GIT_TAG        v1.2.11)
#FetchContent_MakeAvailable(zlib)
#target_link_libraries(lib_core PRIVATE zlibstatic)

target_sources(lib_core
PRIVATE
    installer.core.cpp
PUBLIC
    installer.core.h
)

target_include_directories(lib_core PRIVATE tianli::lib_core::decompression tianli::lib_core::download)

