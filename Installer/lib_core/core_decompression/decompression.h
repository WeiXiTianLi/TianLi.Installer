#pragma once
#include <functional>
#include <optional>
#include <string>
#include <string_view>
#include <fstream>
#include <filesystem>
namespace tianli
{
    namespace core
    {
        std::optional<std::string> decompression(std::filesystem::path file, std::filesystem::path target_dir, std::function<void(int, int)> progress);
    } // namespace core
} // namespace tianli