#include <iostream>
#include <string>
#include <vector>

template <typename Iterator, typename Value>
auto myFind(Iterator first, Iterator last, Value const& value)
{
    while (first != last && *first != value)
    {
        ++first;
    }
    return first;
}

int main()
{
    std::vector<int> vi{1, 2, 3};
    std::cout << *myFind(vi.begin(), vi.end(), 2);

    return 0;
}
