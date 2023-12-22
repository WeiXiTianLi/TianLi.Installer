add_library(lib_core_decompression STATIC)
add_library(tianli::lib_core::decompression ALIAS lib_core_decompression)

include(FetchContent)
set(MZ_FORCE_FETCH_LIBS ON)
set(ZLIB_REPOSITORY "https://github.com/zlib-ng/zlib-ng")
set(ZLIB_TAG "develop")
FetchContent_Declare(minizip GIT_REPOSITORY https://github.com/GengGode/minizip-ng
    GIT_TAG        develop)
FetchContent_MakeAvailable(minizip)

target_sources(lib_core_decompression
    PRIVATE
        decompression.cpp
    PUBLIC
        decompression.h
)

target_link_libraries(lib_core_decompression
    PUBLIC
        minizip 
)