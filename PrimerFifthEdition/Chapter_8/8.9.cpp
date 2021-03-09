#include <iostream>
#include <sstream>
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
    std::istringstream istrst("arst neio zxcv bkm, qwfp gjlu y;[]");
    func(istrst);

    return 0;
}
