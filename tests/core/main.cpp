#include <iostream>
#include <filesystem>
#include <installer.core.h>

int main(int argc, char *argv[])
{
    std::cout << "Hello, World!" << std::endl;
    std::cout << "argc: " << argc << std::endl;
    for (int i = 0; i < argc; ++i)
    {
        std::cout << "argv[" << i << "]: " << argv[i] << std::endl;
    }
#if 1
    std::cout << "DEBUG" << std::endl;
    auto zip = "./test.zip";
    auto dir = "./unzip";
    if (auto res = tianli::decompression(
            std::filesystem::path(zip), std::filesystem::path(dir), [](int a, int b)
            { std::cout << a << " " << b << std::endl; },
            [](bool success)
            { std::cout << "decompression success: " << success << std::endl; });
        res.has_value())
    {
        std::cout << "decompression failed: " << *res << std::endl;
    }
    else
    {
        std::cout << "decompression success" << std::endl;
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
