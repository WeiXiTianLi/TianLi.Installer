add_library(lib_core STATIC)
add_library(tianli::lib_core ALIAS lib_core)

find_package(cpr CONFIG REQUIRED)
target_link_libraries(lib_core PRIVATE cpr::cpr)
find_package(libzippp CONFIG REQUIRED)
target_link_libraries(lib_core PRIVATE libzippp::libzippp)
find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(lib_core PRIVATE nlohmann_json::nlohmann_json)
find_package(fmt CONFIG REQUIRED)
target_link_libraries(lib_core PRIVATE fmt::fmt)
find_package(spdlog CONFIG REQUIRED)
target_link_libraries(lib_core PRIVATE spdlog::spdlog_header_only)

