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

tianli_error *tianli_error::create()
{
    return new tianli_error();
}

void tianli_error::destroy(tianli_error *error)
{
    delete error;
    error = nullptr;
}

bool download(char *url, char *file, void (*progress)(int, int), void (*result)(bool), tianli_error *error)
{
    if (auto res = tianli::download(url, file, progress, result); res.has_value())
    {
        auto message = res.value();
        error->code = 1;
        error->message = (char *)malloc(message.size() + 1);
        if (error->message)
        {
            memcpy(error->message, message.data(), message.size());
            error->message[message.size()] = '\0';
        }
        return false;
    }
    return true;
}

// EXPORT bool download(char *url, char *file, void (*progress)(int, int), void (*result)(bool), tianli_error *error);
// EXPORT bool decompression(char *file, char *target_dir, void (*progress)(int, int), void (*result)(bool), tianli_error *error);
// EXPORT bool install(char *files_dir, char *install_dir, void (*progress)(int, int), tianli_error *error);
// EXPORT bool registration(char *key, char *value, tianli_error *error);
