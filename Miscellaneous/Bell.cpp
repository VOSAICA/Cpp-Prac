#include <Windows.h>
#include <iostream>

int main()
{
    for (int j = 1; j <= 10; ++j)
    {
        std::cout << '\a' << "Bell" << j << '\n';
        Sleep(1500);
    }
    system("pause");

    return 0;
}
