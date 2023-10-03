add_library(lib_core_download STATIC)
add_library(tianli::lib_core::download ALIAS lib_core_download)

include(FetchContent)
# cpr
FetchContent_Declare(
    cpr
    GIT_REPOSITORY https://github.com/GengGode/cpr
    GIT_TAG 1.10.4)
FetchContent_MakeAvailable(cpr)
target_link_libraries(lib_core_download PRIVATE cpr::cpr)

target_sources(lib_core_download
    PRIVATE
        download.cpp
    PUBLIC
        download.h
)