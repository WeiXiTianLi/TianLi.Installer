add_library(core_release STATIC)
add_library(tianli::core::release ALIAS core_release)


target_sources(core_release
    PRIVATE
        release.cpp
)