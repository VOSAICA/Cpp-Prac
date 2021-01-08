#include <iostream>

int main()
{
    int start, end;
    std::cin >> start >> end;

    if (start > end)
    {
        int temp = start;
        start = end;
        end = temp;
    }

    ++start;
    while (start < end)
    {
        std::cout << start << " ";
        ++start;
    }
    return 0;
}
