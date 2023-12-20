get_filename_component(dir_name ${CMAKE_CURRENT_SOURCE_DIR} NAME)
set(test_name test_${dir_name})
add_executable(${test_name} main.cpp)

if(MSVC)
include(FetchContent)
# zlib
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
message(STATUS "zlib_SOURCE_DIR: ${zlib_SOURCE_DIR}")
else()
find_package(ZLIB REQUIRED)
target_link_libraries(${test_name} PRIVATE ZLIB::ZLIB)
endif()


if(MSVC)
    set_property(TARGET ${test_name} PROPERTY  MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    target_compile_options(${test_name} PRIVATE "/W2")
else()
    target_compile_options(${test_name} PRIVATE "-Wall" "-Wextra" "-Wpedantic" )
endif()
string(REPLACE "_" ";" test_name_splits ${test_name})
list(GET test_name_splits 1 test_group_name)
set_target_properties(${test_name} PROPERTIES FOLDER "tests/${test_group_name}")
target_link_libraries(${test_name} ${OpenCV_LIBS})
add_test(NAME ${test_name} COMMAND ${test_name})