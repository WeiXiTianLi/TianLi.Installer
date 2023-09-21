#pragma once
namespace tianli
{
    void download(const char* url, const char* filename, void (*progress)(int, int));


}