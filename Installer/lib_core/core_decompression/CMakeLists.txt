add_library(core_decompression STATIC)
add_library(tianli::core::decompression ALIAS core_decompression)

# add -fPIC
# set_property(TARGET core_decompression PROPERTY POSITION_INDEPENDENT_CODE ON)

include(FetchContent)
set(MZ_FETCH_LIBS ON)
set(MZ_LZMA OFF)
set(MZ_ZSTD OFF)
FetchContent_Declare(minizip GIT_REPOSITORY https://github.com/GengGode/minizip-ng
    GIT_TAG        develop)
FetchContent_MakeAvailable(minizip)

target_link_libraries(core_decompression PRIVATE minizip)

target_sources(core_decompression
    PRIVATE
        decompression.cpp
)
