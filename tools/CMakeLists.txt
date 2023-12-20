
set(BUILD_TOOLS ON CACHE BOOL "Build tools")

if (BUILD_TOOLS)
    auto_subdirectory()
endif()