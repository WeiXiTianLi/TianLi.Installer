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
    tianli_error err;
    if (decompression(
            std::filesystem::path(zip).string().c_str(), std::filesystem::path(dir).string().c_str(), +[](int a, int b)
            { std::cout << a << " " << b << std::endl; },
            +[](bool success)
            { std::cout << "decompression success: " << success << std::endl; }, &err))
    {
        std::cout << "decompression failed: " << err.message << std::endl;
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
