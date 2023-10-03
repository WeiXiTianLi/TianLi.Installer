#include "installer.core.h"
#include "core_decompression/decompression.h"
#include "core_download/download.h"
#include "core_install/install.h"
#include "core_registration/registration.h"
namespace tianli
{
    std::optional<std::string> download(std::string_view url, std::filesystem::path file, std::function<void(int, int)> progress)
    {
        return core::download(url, file, progress);
    }
    std::optional<std::string> decompression(std::filesystem::path file, std::filesystem::path target_dir, std::function<void(int, int)> progress)
    {
        return core::decompression(file, target_dir, progress);
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
