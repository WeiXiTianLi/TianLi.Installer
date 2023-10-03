#include "decompression.h"

// #include <libzip/libzip.h>
#include <zlib.h>
#include <zip.h>

namespace tianli
{
    namespace core
    {
        std::optional<std::string> decompression(std::filesystem::path file, std::filesystem::path target_dir, std::function<void(int, int)> progress)
        {
            if (!std::filesystem::exists(file))
            {
                return std::nullopt;
            }
            if (!std::filesystem::exists(target_dir))
            {
                std::filesystem::create_directories(target_dir);
            }
            if (file.extension() != ".zip")
            {
                return std::nullopt;
            }
#ifdef ZLIB_H_
            // zlib 解压缩 zip
            auto file_name = file.string();
            auto target_dir_name = target_dir.string();

            auto zip = zip_open(file_name.c_str(), 0, nullptr);
            if (zip == nullptr)
            {
                return std::nullopt;
            }
#else
            // 解压缩zip
            auto file_name = file.filename().string();
            auto target_dir_name = target_dir.filename().string();
            auto target_dir_parent = target_dir.parent_path().string();
            auto command = fmt::format("powershell.exe -Command \"& {{Add-Type -AssemblyName System.IO.Compression.FileSystem; [System.IO.Compression.ZipFile]::ExtractToDirectory('{}', '{}');}}\"", file_name, target_dir_name);
            auto res = std::system(command.c_str());
            if (res != 0)
            {
                return std::nullopt;
            }
#endif

            return target_dir.string();
        }
    } // namespace core
} // namespace tianli
