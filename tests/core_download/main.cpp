#include <iostream>
#include <filesystem>
#include <core_download/download.h>

int main(int argc, char *argv[])
{
    std::cout << "Hello, World!" << std::endl;
    std::cout << "argc: " << argc << std::endl;
    for (int i = 0; i < argc; ++i)
    {
        std::cout << "argv[" << i << "]: " << argv[i] << std::endl;
    }
#if 1
    if (auto res = tianli::core::download("http://download.weixitianli.com/d/TianLiUpdateService/cvAutoTrack/cvAutoTrack-7.11.1.zip", std::filesystem::path("./test_download.zip"), [](int a, int b)
                                          { std::cout << a << " " << b << std::endl; });
        res.has_value())
    {
        std::cout << "download failed: " << *res << std::endl;
    }
    else
    {
        std::cout << "download success" << std::endl;
    }
#else
    if (argc != 3)
    {
        std::cout << "Usage: " << argv[0] << " <input file> <output dir>" << std::endl;
        return 1;
    }
    tianli::core::decompression(std::filesystem::path(argv[1]), std::filesystem::path(argv[2]), [](int a, int b)
                                { std::cout << a << " " << b << std::endl; });
#endif
}
