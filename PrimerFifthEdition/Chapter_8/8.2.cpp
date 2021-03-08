#include <iostream>
#include <string>

std::istream& func(std::istream& ist)
{
    std::string temp;
    while (!ist.eof())
    {
        ist >> temp;
        std::cout << temp << std::endl;
    }
    ist.clear();
    return ist;
}

int main()
{
    func(std::cin);

    return 0;
}
