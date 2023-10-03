#include "installer.core.h"
#include "core_decompression/decompression.h"
#include "core_download/download.h"
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
} // namespace tianli
