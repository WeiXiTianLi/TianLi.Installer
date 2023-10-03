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


target_sources(lib_core
PRIVATE
    installer.core.h
    installer.core.cpp
)

