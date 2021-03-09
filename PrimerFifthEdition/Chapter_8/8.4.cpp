#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> func()
{
    std::ifstream ifs("file.txt");
    std::vector<std::string> vec;
    std::string str;
    if (ifs)
    {
        while (std::getline(ifs, str))
        {
            vec.emplace_back(str);
        }
    }

    return vec;
}

int main()
{
    auto a = func();
    for (auto i : a)
    {
        std::cout << i << std::endl;
    }

    return 0;
}
