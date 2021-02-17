#include <cstring>
#include <iostream>

int main()
{
    const char a[6] = {'1', '2', '3', '4', 'e', '\0'};
    const char b[2] = {'c', '\0'};

    char c[9] = {};
    strcpy(c, a);
    strcat(c, b);

    std::cout << c;

    for (auto i : c)
        std::cout << i << ' ';

    std::cout << '\n' << strlen(c);

    return 0;
}
