#include <iostream>
#include <string>
#include <vector>

template <typename T>
size_t count(const std::vector<T>& container, T item)
{
    size_t ret = 0;
    for (const auto& i : container)
    {
        if (i == item)
        {
            ++ret;
        }
    }
    return ret;
}

int main()
{
    std::vector<int> vi{0, 1, 2, 3, 4, 5, 6, 7, 7, 8, 9};
    std::vector<double> vd{0, 1, 2, 3, 4, 5, 6, 7, 7, 8, 9};
    std::vector<std::string> vs{
        "art",
        "back",
    };

    std::cout << count(vi, 7) << count(vd, 7.0) << count(vs, std::string(""));

    return 0;
}
