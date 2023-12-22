add_library(lib_core_download STATIC)
add_library(tianli::lib_core::download ALIAS lib_core_download)

include(FetchContent)
# cpr
if(NOT WIN32)
    set(CPR_ENABLE_SSL OFF)
    set(CURL_ZLIB OFF)
else()
    set(ENABLE_THREADED_RESOLVER OFF)
    set(CPR_ENABLE_SSL ON)
    set(CPR_ENABLE_CURL_HTTP_ONLY OFF)
    set(CPR_FORCE_WINSSL_BACKEND ON)
endif()

if(NOT WIN32)
    set(pthreads_lib pthread)
endif()

FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr
    GIT_TAG 1.10.4)
FetchContent_MakeAvailable(cpr)
target_link_libraries(lib_core_download PRIVATE cpr::cpr ${pthreads_lib})

target_sources(lib_core_download
    PRIVATE
        download.cpp
    PUBLIC
        download.h
)