#include <iostream>
#include <filesystem>
#include "../../../Installer/lib_core/core_decompression/decompression.h"



int main(int argc, char* argv[])
{
    std::cout << "Hello, World!" << std::endl;
    std::cout << "argc: " << argc << std::endl;
    for (int i = 0; i < argc; ++i)
    {
        std::cout << "argv[" << i << "]: " << argv[i] << std::endl;
    }
    #if 1
    std::cout << "DEBUG" << std::endl;
    #ifdef _WIN32
    auto zip = "D:/library/TianLi.Installer/build/tests/core_decompression/test.zip";
    auto dir = "D:/library/TianLi.Installer/build/tests/core_decompression/unzip";
    #else
    auto zip = "/home/ysx/library/TianLi.Installer/build/tests/core_decompression/test.zip";
    auto dir = "/home/ysx/library/TianLi.Installer/build/tests/core_decompression/unzip";
    #endif
    if(auto res = tianli::core::decompression(std::filesystem::path(zip), std::filesystem::path(dir), [](int a, int b) { std::cout << a << " " << b << std::endl; }); res.has_value())
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
    tianli::core::decompression(std::filesystem::path(argv[1]), std::filesystem::path(argv[2]), [](int a, int b) { std::cout << a << " " << b << std::endl; });
    #endif

}
