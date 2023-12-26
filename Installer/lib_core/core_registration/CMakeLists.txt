add_library(core_registration STATIC)
add_library(tianli::core::registration ALIAS core_registration)


target_sources(core_registration
    PRIVATE
        registration.cpp
)