add_library(lib_core_decompression STATIC)
add_library(tianli::lib_core::decompression ALIAS lib_core_decompression)

if(MSVC)
message(STATUS "MSVC")
include(FetchContent)
# minizip requires zlib
FetchContent_Declare(minizip GIT_REPOSITORY https://github.com/zlib-ng/minizip-ng
    GIT_TAG        4.0.1)
FetchContent_MakeAvailable(minizip)
target_link_libraries(${test_name} PRIVATE zlibstatic)
# include zlib
target_include_directories(${test_name} PUBLIC ${zlib_SOURCE_DIR})
# include zconf.h
target_include_directories(${test_name} PUBLIC ${zlib_BINARY_DIR})
# include minizip
target_include_directories(${test_name} PUBLIC "${zlib_SOURCE_DIR}/contrib/minizip/")
else()
# gcc
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    message(STATUS "GNU|Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
endif()
include(FetchContent)
# minizip requires zlib 
# MZ_CODE_COVERAGE=ON -D MZ_FORCE_FETCH_LIBS=ON
set(MZ_CODE_COVERAGE ON)
# set(MZ_FORCE_FETCH_LIBS ON)
FetchContent_Declare(minizip GIT_REPOSITORY https://github.com/zlib-ng/minizip-ng
    GIT_TAG        4.0.1)
FetchContent_MakeAvailable(minizip)
endif()

target_sources(lib_core_decompression
    PRIVATE
        decompression.cpp
    PUBLIC
        decompression.h
)

target_include_directories(lib_core_decompression
    PUBLIC
        ${zlib_SOURCE_DIR}
)

target_link_libraries(lib_core_decompression
    PUBLIC
        minizip 
)