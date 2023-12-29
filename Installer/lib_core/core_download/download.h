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
        std::optional<std::string> download(std::string_view url, std::filesystem::path file, std::function<void(int, int)> progress, std::function<void(bool)> result);
    } // namespace core
} // namespace tianli