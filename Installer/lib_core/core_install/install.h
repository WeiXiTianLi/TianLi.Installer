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
        std::optional<std::string> install(std::filesystem::path files_dir, std::filesystem::path install_dir, std::function<void(int, int)> progress);
    } // namespace core
} // namespace tianli