add_library(lib_core_download STATIC)
add_library(tianli::lib_core::download ALIAS lib_core_download)

include(FetchContent)
# cpr
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr
    GIT_TAG 1.10.4)
FetchContent_MakeAvailable(cpr)
if(NOT OPENSSL_FOUND)
message(STATUS "OpenSSL not found, using insecure cpr")
message(STATUS "可能需要运行: sudo apt-get install libssl-dev")
endif()

if(NOT WIN32)
    set(pthreads_lib pthread)
endif()
target_link_libraries(lib_core_download PRIVATE cpr::cpr ${pthreads_lib})

target_sources(lib_core_download
    PRIVATE
        download.cpp
    PUBLIC
        download.h
)