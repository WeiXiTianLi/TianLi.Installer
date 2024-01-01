#pragma once
#include <string>
#include <optional>
#include <functional>
#include <filesystem>
#include <string_view>
namespace tianli
{
#ifdef CAPI_CORE
    void download(const char *url, const char *filename, void (*progress)(int, int));
    void decompression(const char *file_path, const char *target_dir, void (*progress)(int, int));
    void install(const char *files_dir, const char *install_dir, void (*progress)(int, int));
    void registration(const char *key, const char *value);
#endif
    std::optional<std::string> download(std::string_view url, std::filesystem::path file, std::function<void(int, int)> progress, std::function<void(bool)> result);
    std::optional<std::string> decompression(std::filesystem::path file, std::filesystem::path target_dir, std::function<void(int, int)> progress, std::function<void(bool)> result);
    std::optional<std::string> install(std::filesystem::path files_dir, std::filesystem::path install_dir, std::function<void(int, int)> progress);
    std::optional<std::string> registration(std::string_view key, std::string_view value);
} // namespace tianli
