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
    auto zip = "D:/library/TianLi.Installer/build/tests/core_decompression/cmake_install.zip";
    auto dir = "D:/library/TianLi.Installer/build/tests/core_decompression/unzip";
    tianli::core::decompression(std::filesystem::path(zip), std::filesystem::path(dir), [](int a, int b) { std::cout << a << " " << b << std::endl; });
    #else
        if (argc != 3)
    {
        std::cout << "Usage: " << argv[0] << " <input file> <output dir>" << std::endl;
        return 1;
    }
    tianli::core::decompression(std::filesystem::path(argv[1]), std::filesystem::path(argv[2]), [](int a, int b) { std::cout << a << " " << b << std::endl; });
    #endif

}
