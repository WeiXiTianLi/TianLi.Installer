add_library(core_download STATIC)
add_library(tianli::core::download ALIAS core_download)

include(FetchContent)
# cpr
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr
    GIT_TAG 1.10.4)
FetchContent_MakeAvailable(cpr)
if(NOT OPENSSL_FOUND)
    message(STATUS "OpenSSL not found, using insecure cpr")
    message(STATUS "可能需要运行: sudo apt-get install libssl-dev")
endif()

target_link_libraries(core_download PRIVATE cpr::cpr)

target_sources(core_download
    PRIVATE
        download.cpp
)