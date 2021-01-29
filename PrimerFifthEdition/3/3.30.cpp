#include <cstddef>
#include <iostream>

constexpr size_t array_size = 10;
int ia[array_size];

int main()
{
    for (size_t ix = 1; ix <= array_size; ++ix) //下标越界，应改成 ix < array_size;
        ia[ix] = ix;

    for (auto x : ia)
        std::cout << x;

    return 0;
}
