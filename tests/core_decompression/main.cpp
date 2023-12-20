#include <iostream>
#include <filesystem>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#include <fcntl.h>
#endif



int main(int argc, char* argv[])
{
    std::cout << "Hello, World!" << std::endl;
    std::cout << "argc: " << argc << std::endl;
    for (int i = 0; i < argc; ++i)
    {
        std::cout << "argv[" << i << "]: " << argv[i] << std::endl;
    }


}
