add_library(lib_core_download STATIC)
add_library(tianli::lib_core::download ALIAS lib_core_download)

include(FetchContent)
# cpr
set(CPR_ENABLE_SSL OFF)
set(CURL_ZLIB OFF)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr
    GIT_TAG 1.9.7)
FetchContent_MakeAvailable(cpr)
target_link_libraries(lib_core_download PRIVATE cpr::cpr)

target_sources(lib_core_download
    PRIVATE
        download.cpp
    PUBLIC
        download.h
)