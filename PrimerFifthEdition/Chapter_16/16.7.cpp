#include <iostream>

template <typename T, unsigned int size>
constexpr int arraySize(T (&array)[size])
{
    return size;
}

int main()
{
    int a[99];

    std::cout << arraySize(a) << std::endl;

    return 0;
}
