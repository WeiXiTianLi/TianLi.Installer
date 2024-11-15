add_library(core_decompression STATIC)
add_library(tianli::core::decompression ALIAS core_decompression)

include(FetchContent)
set(MZ_FETCH_LIBS ON)
set(MZ_LZMA OFF)
set(MZ_ZSTD OFF)
set(MZ_BUILD_TEST OFF)
set(ZLIB_ENABLE_TESTS OFF)
set(ZLIB_TAG develop)
FetchContent_Declare(minizip GIT_REPOSITORY https://github.com/zlib-ng/minizip-ng
    GIT_TAG        master)
FetchContent_MakeAvailable(minizip)
set_property(TARGET bzip2 PROPERTY POSITION_INDEPENDENT_CODE ON)

target_link_libraries(core_decompression PRIVATE minizip)

target_sources(core_decompression
    PRIVATE
        decompression.cpp
)
