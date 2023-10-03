add_library(lib_core_install STATIC)
add_library(tianli::lib_core::install ALIAS lib_core_install)


target_sources(lib_core_install
    PRIVATE
        install.cpp
    PUBLIC
        install.h
)