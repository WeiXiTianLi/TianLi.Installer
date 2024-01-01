#pragma once

#ifdef __cplusplus
#include <string>
#include <optional>
#include <functional>
#include <filesystem>
#include <string_view>
namespace tianli
{
    std::optional<std::string> download(std::string_view url, std::filesystem::path file, std::function<void(int, int)> progress, std::function<void(bool)> result);
    std::optional<std::string> decompression(std::filesystem::path file, std::filesystem::path target_dir, std::function<void(int, int)> progress, std::function<void(bool)> result);
    std::optional<std::string> install(std::filesystem::path files_dir, std::filesystem::path install_dir, std::function<void(int, int)> progress);
    std::optional<std::string> registration(std::string_view key, std::string_view value);
} // namespace tianli
#endif

#ifdef EXPORT_CORE
extern "C"
{
    char *download(char *url, char *file, void (*progress)(int, int), void (*result)(bool));
    char *decompression(char *file, char *target_dir, void (*progress)(int, int), void (*result)(bool));
    char *install(char *files_dir, char *install_dir, void (*progress)(int, int));
    char *registration(char *key, char *value);
}
#endif