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
        std::optional<std::pair<void *, size_t>> release(std::string_view key, std::string_view value);
    } // namespace core
} // namespace tianli