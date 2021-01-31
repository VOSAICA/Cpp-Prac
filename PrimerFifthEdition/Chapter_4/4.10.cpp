#include <iostream>

int main()
{
    int a, i;
    while (std::cin >> a && a != 42)
    {
        std::cout << ++i << "个了";
    }

    return 0;
}
