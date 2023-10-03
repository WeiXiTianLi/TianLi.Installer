#include "download.h"
#include <cpr/cpr.h>

namespace tianli
{
    namespace core
    {
        std::optional<std::string> download(std::string_view url, std::filesystem::path file, std::function<void(int, int)> progress)
        {
            auto dir = file.parent_path();
            if (!std::filesystem::exists(dir))
            {
                std::filesystem::create_directories(dir);
            }
            auto file_name = file.filename().string();
            if (std::filesystem::exists(file))
            {
                std::filesystem::remove(file);
            }

            auto progress_callback = [&](__int64 downloadTotal, __int64 downloadNow, __int64 uploadTotal, __int64 uploadNow, intptr_t userdata) -> bool
            {
                progress(downloadNow, downloadTotal);
                return true;
            };

            auto res = cpr::Get(cpr::Url{url},
                                cpr::Timeout{10000},
                                cpr::ProgressCallback{progress_callback});

            if (res.status_code != 200)
            {
                return std::nullopt;
            }

            std::ofstream file_stream(file, std::ios::binary);
            file_stream.write(res.text.data(), res.text.size());
            file_stream.close();
            return file.string();
        }
    } // namespace core
} // namespace tianli
