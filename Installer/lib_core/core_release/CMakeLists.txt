add_library(lib_core_release STATIC)
add_library(tianli::lib_core::release ALIAS lib_core_release)


target_sources(lib_core_release
    PRIVATE
        release.cpp
    PUBLIC
        release.h
)