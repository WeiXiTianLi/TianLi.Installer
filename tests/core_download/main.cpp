#include <iostream>
#include <filesystem>
#include <core_download/download.h>

int main(int argc, char* argv[])
{
    std::cout << "Hello, World!" << std::endl;
    std::cout << "argc: " << argc << std::endl;
    for (int i = 0; i < argc; ++i)
    {
        std::cout << "argv[" << i << "]: " << argv[i] << std::endl;
    }
    #if 1
    if(auto res = tianli::core::download("http://pipelinesghubeus26.actions.githubusercontent.com/aR8v56Dl2mnbs0kz13kZVXVVeFjoZE3HNDeXxB5WdWwIyIKVZh/_apis/pipelines/1/runs/251/signedartifactscontent?artifactName=cvAutoTrack&urlExpires=2023-12-22T06%3A35%3A05.8988433Z&urlSigningMethod=HMACV2&urlSignature=%2FjPG1l5AULPz4dbd4uJ03yizNbw5ZqXsDPV5bY63KYs%3D", std::filesystem::path("D:/library/TianLi.Installer/build/tests/core_download/test.zip"), [](int a, int b) { std::cout << a << " " << b << std::endl; }); res.has_value())
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
    tianli::core::decompression(std::filesystem::path(argv[1]), std::filesystem::path(argv[2]), [](int a, int b) { std::cout << a << " " << b << std::endl; });
    #endif

}
