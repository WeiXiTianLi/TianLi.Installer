add_library(lib_core_decompression STATIC)
add_library(tianli::lib_core::decompression ALIAS lib_core_decompression)


include(FetchContent)
# zlib
FetchContent_Declare(zlib GIT_REPOSITORY https://github.com/madler/zlib
    GIT_TAG        v1.2.11)
FetchContent_MakeAvailable(zlib)
target_link_libraries(lib_core_decompression PRIVATE zlibstatic)

target_sources(lib_core_decompression
    PRIVATE
        decompression.cpp
    PUBLIC
        decompression.h
)