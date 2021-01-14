#include <iostream>

int main()
{
    int i, &ri = i;
    i = 5;
    ri = 10;
    const int *ptr = &i;
    std::cout << i << " " << ri << std::endl; //10 10

    *ptr = 6;

    return 0;
}
