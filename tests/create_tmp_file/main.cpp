#include <iostream>
#include <filesystem>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#include <fcntl.h>
#endif

std::filesystem::path get_tmp_path()
{
#ifdef _WIN32
    char tmp_dir[MAX_PATH];
    DWORD len = GetTempPath(MAX_PATH, tmp_dir);
    if (len == 0 || len > MAX_PATH)
    {
        return "";
    }
    return std::filesystem::path(tmp_dir);
#else
    const char* tmp_dir = getenv("TMPDIR");
    if (tmp_dir == NULL)
    {
        tmp_dir = "/tmp";
    }
    return std::filesystem::path(tmp_dir);
#endif
}

std::string get_tmp_dir()
{
#ifdef _WIN32
    char tmp_dir[MAX_PATH];
    DWORD len = GetTempPath(MAX_PATH, tmp_dir);
    if (len == 0 || len > MAX_PATH)
    {
        return "";
    }
    return std::string(tmp_dir);
#else
    const char* tmp_dir = getenv("TMPDIR");
    if (tmp_dir == NULL)
    {
        tmp_dir = "/tmp";
    }
    return std::string(tmp_dir);
#endif
}

bool create_random_tmp_dir(std::string& tmp_dir)
{
#ifdef _WIN32
    char tmp_dir_chars[MAX_PATH];
    DWORD len = GetTempPath(MAX_PATH, tmp_dir_chars);
    if (len == 0 || len > MAX_PATH)
    {
        return false;
    }
    if (GetTempFileName(tmp_dir_chars, "tianli", 0, tmp_dir_chars) == 0)
    {
        return false;
    }
    DeleteFile(tmp_dir_chars);
    if (CreateDirectory(tmp_dir_chars, NULL) == 0)
    {
        return false;
    }
    tmp_dir = tmp_dir_chars;
#else
    const char* tmp_dir_chars = getenv("TMPDIR");
    if (tmp_dir_chars == NULL)
    {
        tmp_dir_chars = "/tmp";
    }
    std::string tmp_dir_template = std::string(tmp_dir_chars) + "/tianli.XXXXXX";
    char* tmp_dir_ptr = mkdtemp(&tmp_dir_template[0]);
    if (tmp_dir_ptr == NULL)
    {
        return false;
    }
    tmp_dir = tmp_dir_ptr;
#endif
    return true;
}

bool create_random_tmp_dir(std::filesystem::path& tmp_dir)
{
#ifdef _WIN32
    char tmp_dir_chars[MAX_PATH];
    DWORD len = GetTempPath(MAX_PATH, tmp_dir_chars);
    if (len == 0 || len > MAX_PATH)
    {
        return false;
    }
    if (GetTempFileName(tmp_dir_chars, "tianli", 0, tmp_dir_chars) == 0)
    {
        return false;
    }
    DeleteFile(tmp_dir_chars);
    if (CreateDirectory(tmp_dir_chars, NULL) == 0)
    {
        return false;
    }
    tmp_dir = tmp_dir_chars;
#else
    const char* tmp_dir_chars = getenv("TMPDIR");
    if (tmp_dir_chars == NULL)
    {
        tmp_dir_chars = "/tmp";
    }
    std::string tmp_dir_template = std::string(tmp_dir_chars) + "/tianli.XXXXXX";
    char* tmp_dir_ptr = mkdtemp(&tmp_dir_template[0]);
    if (tmp_dir_ptr == NULL)
    {
        return false;
    }
    tmp_dir = tmp_dir_ptr;
#endif
    return true;
}

bool create_random_tmp_file(const std::filesystem::path& tmp_dir, std::filesystem::path& tmp_file)
{
#ifdef _WIN32
    char tmp_file_chars[MAX_PATH];
    if (GetTempFileNameA(tmp_dir.string().c_str(), "tianli", 0, tmp_file_chars) == 0)
    {
        return false;
    }
    tmp_file = tmp_file_chars;
#else
    std::string tmp_file_template = std::string(tmp_dir.c_str()) + "/tianli.XXXXXX";
    int fd = mkstemp(&tmp_file_template[0]);
    if (fd == -1)
    {
        return false;
    }
    close(fd);
    tmp_file = tmp_file_template;
#endif
    return true;
}

bool create_tmp_file(std::string& tmp_file)
{
    std::filesystem::path tmp_dir;
    if (!create_random_tmp_dir(tmp_dir))
    {
        return false;
    }
    std::filesystem::path tmp_file_path;
    if (!create_random_tmp_file(tmp_dir, tmp_file_path))
    {
        return false;
    }
    tmp_file = tmp_file_path.string();
    return true;
}



int main(int argc, char* argv[])
{
    std::cout << "Hello, World!" << std::endl;
    std::cout << "argc: " << argc << std::endl;
    for (int i = 0; i < argc; ++i)
    {
        std::cout << "argv[" << i << "]: " << argv[i] << std::endl;
    }

    std::string tmp_dir = get_tmp_dir();
    if (tmp_dir.empty())
    {
        std::cout << "Failed to get tmp dir" << std::endl;
        return 1;
    }
    std::cout << "tmp_dir: " << tmp_dir << std::endl;

    std::string tmp_dir2;
    if (!create_random_tmp_dir(tmp_dir2))
    {
        std::cout << "Failed to create random tmp dir" << std::endl;
        return 1;
    }
    std::cout << "tmp_dir2: " << tmp_dir2 << std::endl;

    std::filesystem::path tmp_dir3;
    if (!create_random_tmp_dir(tmp_dir3))
    {
        std::cout << "Failed to create random tmp dir" << std::endl;
        return 1;
    }
    std::cout << "tmp_dir3: " << tmp_dir3 << std::endl;

    std::string tmp_file;
    if (!create_tmp_file(tmp_file))
    {
        std::cout << "Failed to create tmp file" << std::endl;
        return 1;
    }
    std::cout << "tmp_file: " << tmp_file << std::endl;


}
