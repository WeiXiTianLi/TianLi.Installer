add_library(core_install STATIC)
add_library(tianli::core::install ALIAS core_install)


target_sources(core_install
    PRIVATE
        install.cpp
)