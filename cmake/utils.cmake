function(tianli_parse_version)
    file(READ ${CMAKE_CURRENT_LIST_DIR}/config/version.ver version_file_contents)
    message(STATUS "version: ${version_file_contents}")
endfunction()