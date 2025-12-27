#include <filesystem>
#include <iostream>
#include <string>

namespace fs = std::filesystem;

void clear()
{
    for (const auto& entry : fs::directory_iterator("."))
    {
        if (entry.is_regular_file())
        {
            const auto& path = entry.path();
            if (path.extension() == ".dat")
            {
                fs::remove(path);
            }
        }
    }
}

int main()
{
    clear();
    return 0;
}