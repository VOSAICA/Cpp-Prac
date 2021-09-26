#include <cstring>
#include <iostream>
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

template <>
size_t count(const std::vector<const char*>& container, const char* item)
{
    size_t ret = 0;
    for (const auto& i : container)
    {
        if (strcmp(i, item) == 0)
        {
            ++ret;
        }
    }
    return ret;
}

int main()
{
    std::vector<const char*> vcc{"ars", "back", "back", "back", "back"};
    std::cout << count(vcc, "back");

    return 0;
}
