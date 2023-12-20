
set(BUILD_TESTS ON CACHE BOOL "Build tests")

if(MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

if(MSVC)
    #cpp20
    add_compile_options(/std:c++latest)
else()
    add_compile_options(-std=c++2a)
endif()

if (BUILD_TESTS)
    auto_subdirectory()
endif()