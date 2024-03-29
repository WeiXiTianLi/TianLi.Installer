#include "decompression.h"

// #include <zlib.h>
#include "unzip.h"

#define _used_unz64

namespace tianli
{
    namespace core
    {
        std::optional<std::string> decompression(std::filesystem::path file, std::filesystem::path target_dir, std::function<void(int, int)> progress, std::function<void(bool)> result)
        {
            auto ret_error = [&](std::string_view error) -> std::optional<std::string> {
                if (result) result(false);
                return error.data();
            };

            if (!std::filesystem::exists(file))
                return ret_error("file not exists");
            if (!std::filesystem::exists(target_dir))
                std::filesystem::create_directories(target_dir);
            if (file.extension() != ".zip")
                return ret_error("file extension not .zip");

#ifdef _used_unz64
            // zlib 解压缩 zip
            auto file_name = file.string();
            auto target_dir_name = target_dir.string();

            unzFile uf = unzOpen64(file_name.c_str());
            if (uf == NULL)
                return ret_error("unzOpen64 failed");
            unz_global_info64 gi;
            if (unzGetGlobalInfo64(uf, &gi) != UNZ_OK)
            {
                unzClose(uf);
                return ret_error("unzGetGlobalInfo64 failed");
            }
            unsigned long i;
            int all_size = 0;
            for (i = 0; i < gi.number_entry; ++i)
            {
                unz_file_info64 file_info;
                char filename[256];
                if (unzGetCurrentFileInfo64(uf, &file_info, filename, sizeof(filename), NULL, 0, NULL, 0) != UNZ_OK)
                {
                    unzClose(uf);
                    return ret_error("call all_size unzGetCurrentFileInfo64 failed");
                }
                all_size += file_info.uncompressed_size;
                unzGoToNextFile(uf);
            }
            unzGoToFirstFile(uf);
            int current_size = 0;
            for (i = 0; i < gi.number_entry; ++i)
            {
                unz_file_info64 file_info;
                char filename[256];
                if (unzGetCurrentFileInfo64(uf, &file_info, filename, sizeof(filename), NULL, 0, NULL, 0) != UNZ_OK)
                {
                    unzClose(uf);
                    return ret_error("call unzGetCurrentFileInfo64 failed");
                }
                auto unz_open_current_file_res = unzOpenCurrentFile(uf);
                if (unz_open_current_file_res != UNZ_OK)
                {
                    unzClose(uf);
                    return ret_error(std::string("unzOpenCurrentFile failed: ") + filename + " " + std::to_string(unz_open_current_file_res));
                }

                std::filesystem::path file_path = target_dir / filename;
                if (file_path.filename().string().empty())
                {
                    unzCloseCurrentFile(uf);
                    continue;
                }
                if (std::filesystem::exists(file_path))
                {
                    std::filesystem::remove(file_path);
                }
                std::filesystem::create_directories(file_path.parent_path());
                std::ofstream file_stream(file_path, std::ios::binary);
                char buf[4096];
                int read;
                while ((read = unzReadCurrentFile(uf, buf, sizeof(buf))) > 0)
                {
                    file_stream.write(buf, read);
                    if (progress)
                    {
                        current_size += read;
                        progress(current_size, all_size);
                    }
                }
                file_stream.close();
                unzCloseCurrentFile(uf);
                unzGoToNextFile(uf);
            }

#else
            // 解压缩zip
            auto file_name = file.filename().string();
            auto target_dir_name = target_dir.filename().string();
            auto target_dir_parent = target_dir.parent_path().string();
            // auto command = fmt::format("powershell.exe -Command \"& {{Add-Type -AssemblyName System.IO.Compression.FileSystem; [System.IO.Compression.ZipFile]::ExtractToDirectory('{}', '{}');}}\"", file_name, target_dir_name);
            auto command = "powershell.exe -Command \"& {Add-Type -AssemblyName System.IO.Compression.FileSystem; [System.IO.Compression.ZipFile]::ExtractToDirectory('" + file_name + "', '" + target_dir_name + "');}\"";
            auto res = std::system(command.c_str());
            if (res != 0)
            {
                return std::nullopt;
            }
#endif
            if (result)
                result(true);
            return std::nullopt;
        }
    } // namespace core
} // namespace tianli
