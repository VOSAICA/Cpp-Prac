#include <iostream>

int main()
{
    int start, end;
    std::cin >> start >> end;
    ++start;
    while (start < end)
    {
        std::cout << start << " ";
        ++start;
    }
    return 0;
}
