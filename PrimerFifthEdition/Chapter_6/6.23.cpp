#include <iostream>
#include <vector>

using std::cout;

void print(const int a)
{
    cout << a << '\n';
}

void print(int* start, int* end)
{
    while (start != end)
    {
        cout << *start++ << ' ';
    }
    cout << '\n';
}

int main()
{
    int i = 0;
    int j[2]{0, 1};
    int *start = std::begin(j), *end = std::end(j);

    print(i);
    print(start, end);

    return 0;
}
