
if(MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

if(MSVC)
    # cpp20
    add_compile_options(/std:c++latest)
    # c99
    # add_compile_options(/std:c99)
else()
    # add_compile_options(-std=c++2a)

endif()

    auto_subdirectory()