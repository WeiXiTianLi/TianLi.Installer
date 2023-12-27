message(STATUS "core")
add_library(core STATIC)
add_library(tianli::core ALIAS core)
# /usr/bin/g++ -std=c++17 -g -static  Installer/CMakeFiles/Installer.dir/main.cpp.o -o bin/Installer  lib/libcore.a  lib/libcore_decompression.a  lib/libminizip.a  -lssl  -lcrypto  lib/libz.a  lib/libbzip2.a  lib/libcore_download.a  lib/libcpr.a  lib/libcurl-d.a  -ldl  -lpthread  /usr/lib/x86_64-linux-gnu/libssl.a  /usr/lib/x86_64-linux-gnu/libcrypto.a  -lpthread  -Wl,-Bstatic lib/libcore_install.a  lib/libcore_registration.a  -Wl,-Bdynamic
# /usr/bin/g++ -std=c++17 -g -static  Installer/CMakeFiles/Installer.dir/main.cpp.o -o bin/Installer  lib/libcore.a  lib/libcore_decompression.a  lib/libminizip.a  -lssl  -lcrypto  lib/libz.a  lib/libbzip2.a  lib/libcore_download.a  lib/libcpr.a  lib/libcurl-d.a  -ldl  -lpthread  /usr/lib/x86_64-linux-gnu/libssl.a  /usr/lib/x86_64-linux-gnu/libcrypto.a  -lpthread  lib/libcore_install.a  lib/libcore_registration.a 


set(BUILD_SHARED_LIBS OFF)
set(BUILD_STATIC_LIBS ON)


# 设置为C++17
set(CMAKE_CXX_STANDARD 20)
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET core PROPERTY CXX_STANDARD 20)
endif()

# add -fPIC
# set_property(TARGET core PROPERTY POSITION_INDEPENDENT_CODE ON)

# 设置UTF-8编码
add_definitions(-DUNICODE -D_UNICODE)
# msvc编译器设置utf-8编码
if (MSVC)
    add_compile_options("/utf-8")
    # 设置编译运行时为静态链接
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif ()


add_subdirectory(core_decompression)
add_subdirectory(core_download)
add_subdirectory(core_install)
add_subdirectory(core_registration)

target_include_directories(core PRIVATE core_decompression)
target_include_directories(core PRIVATE core_download)
target_include_directories(core PRIVATE core_install)
target_include_directories(core PRIVATE core_registration)

target_sources(core
    PRIVATE
        installer.core.cpp
)

target_link_libraries(core PRIVATE 
    tianli::core::decompression 
    tianli::core::download
    tianli::core::install
    tianli::core::registration)
