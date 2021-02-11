#include <iostream>

using std::cout;

int sum(std::initializer_list<int> list)
{
    int sum;
    for (int i : list)
        sum += i;
    return sum;
}

int main()
{
    cout << sum({0, 2, 4, 5, 1, 1});
    return 0;
}
