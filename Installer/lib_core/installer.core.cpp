#include "installer.core.h"
#include <decompression.h>
#include <download.h>
#include <install.h>
#include <registration.h>

namespace tianli
{
    std::optional<std::string> download(std::string_view url, std::filesystem::path file, std::function<void(int, int)> progress, std::function<void(bool)> result)
    {
        return core::download(url, file, progress, result);
    }
    std::optional<std::string> decompression(std::filesystem::path file, std::filesystem::path target_dir, std::function<void(int, int)> progress, std::function<void(bool)> result)
    {
        return core::decompression(file, target_dir, progress, result);
    }
    std::optional<std::string> install(std::filesystem::path files_dir, std::filesystem::path install_dir, std::function<void(int, int)> progress)
    {
        return core::install(files_dir, install_dir, progress);
    }
    std::optional<std::string> registration(std::string_view key, std::string_view value)
    {
        return core::registration(key, value);
    }
} // namespace tianli
