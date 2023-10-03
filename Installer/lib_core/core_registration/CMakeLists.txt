add_library(lib_core_registration STATIC)
add_library(tianli::lib_core::registration ALIAS lib_core_registration)


target_sources(lib_core_registration
    PRIVATE
        registration.cpp
    PUBLIC
        registration.h
)