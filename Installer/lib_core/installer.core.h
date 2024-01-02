#pragma once

// #ifdef __cplusplus
// #include <string>
// #include <optional>
// #include <functional>
// #include <filesystem>
// #include <string_view>
// namespace tianli
// {
//     std::optional<std::string> download(std::string_view url, std::filesystem::path file, std::function<void(int, int)> progress, std::function<void(bool)> result);
//     std::optional<std::string> decompression(std::filesystem::path file, std::filesystem::path target_dir, std::function<void(int, int)> progress, std::function<void(bool)> result);
//     std::optional<std::string> install(std::filesystem::path files_dir, std::filesystem::path install_dir, std::function<void(int, int)> progress);
//     std::optional<std::string> registration(std::string_view key, std::string_view value);
// } // namespace tianli
// #endif

#ifdef __WIN32
#ifdef EXPORT_CORE
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __declspec(dllimport)
#endif
#else
#define EXPORT
#endif

extern "C"
{
    EXPORT struct tianli_error
    {
        int code = 0;
        char *message = nullptr;

        static tianli_error *create();
        static void destroy(tianli_error *error);
    };

    EXPORT bool download(const char *url, const char  *file, void (*progress)(int, int), void (*result)(bool), tianli_error *error);
    EXPORT bool decompression(const char  *file, const char  *target_dir, void (*progress)(int, int), void (*result)(bool), tianli_error *error);
    EXPORT bool install(const char  *files_dir, const char  *install_dir, void (*progress)(int, int), tianli_error *error);
    EXPORT bool registration(const char  *key, const char  *value, tianli_error *error);
}