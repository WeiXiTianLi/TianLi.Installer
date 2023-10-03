#pragma once
#include <functional>
#include <optional>
// #include <expected>
#include <string>
#include <string_view>
#include <fstream>
#include <filesystem>
namespace tianli
{
#ifdef C_CORE
    void download(const char *url, const char *filename, void (*progress)(int, int));
    void decompression(const char *file_path, const char *target_dir, void (*progress)(int, int));
    void install(const char *files_dir, const char *install_dir, void (*progress)(int, int));
    void registration(const char *key, const char *value);
#endif
    // std::expected<void, std::string> download(std::string_view url, std::string_view file_name, std::funciton<void(size_t, size_t)> progress);
    std::optional<std::string> download(std::string_view url, std::filesystem::path file, std::function<void(int, int)> progress);
    // std::expected<void, std::string> decompression(std::string_view file_path, std::string_view target_dir, std::funciton<void(size_t, size_t)> progress);
    std::optional<std::string> decompression(std::filesystem::path file, std::filesystem::path target_dir, std::function<void(int, int)> progress);
    // std::expected<void, std::string> install(std::string_view files_dir, std::string_view install_dir, std::funciton<void(size_t, size_t)> progress);
    // std::expected<void, std::string> registration(std::string_view key, std::string_view value);

} // namespace tianli
