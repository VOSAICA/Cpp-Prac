#include <iostream>

int main()
{
    int in, sum = 0;
    std::cout << "Press Ctrl + Z and then Enter to finish input" << std::endl;
    while (std::cin >> in)
    {
        sum += in;
    }
    std::cout << sum;
    return 0;
}
