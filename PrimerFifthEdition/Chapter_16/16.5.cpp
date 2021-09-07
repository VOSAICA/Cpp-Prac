#include <iostream>

template <typename T, unsigned int size>
void print(T (&array)[size])
{
    for (unsigned int i = 0; i < size; ++i)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    int a[4] = {1, 2, 3, 4};
    int b[100];

    print(a);
    print(b);

    return 0;
}
