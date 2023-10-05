add_library(lib_core_decompression STATIC)
add_library(tianli::lib_core::decompression ALIAS lib_core_decompression)


include(FetchContent)
# zlib
FetchContent_Declare(minizip GIT_REPOSITORY https://github.com/zlib-ng/minizip-ng
    GIT_TAG        4.0.1)
FetchContent_MakeAvailable(minizip)
target_link_libraries(lib_core_decompression PRIVATE zlibstatic)
# include zlib
target_include_directories(lib_core_decompression PUBLIC ${zlib_SOURCE_DIR})
# include zconf.h
target_include_directories(lib_core_decompression PUBLIC ${zlib_BINARY_DIR})
# include minizip
target_include_directories(lib_core_decompression PUBLIC "${zlib_SOURCE_DIR}/contrib/minizip/")
message(STATUS "zlib_SOURCE_DIR: ${zlib_SOURCE_DIR}")


target_sources(lib_core_decompression
    PRIVATE
        decompression.cpp
    PUBLIC
        decompression.h
)