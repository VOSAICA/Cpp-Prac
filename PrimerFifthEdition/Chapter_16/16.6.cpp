#include <iostream>

template <typename T, unsigned int size>
auto begin(T (&array)[size])
{
    return &array[0];
}

template <typename T, unsigned int size>
auto end(T (&array)[size])
{
    return &array[size];
}

int main()
{
    int a[4] = {1, 2, 3, 4};

    for (auto* b = begin(a); b != end(a); ++b)
    {
        std::cout << *b << ' ';
    }

    return 0;
}
