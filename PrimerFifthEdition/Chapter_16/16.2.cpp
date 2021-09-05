#include <iostream>

template <unsigned N, unsigned M>
auto compare(const char (&p1)[N], const char (&p2)[M]) -> int
{
    return strcmp(p1, p2);
}

auto main() -> int
{
    std::cout << compare("ABC", "AB") << std::endl;
    std::cout << compare("AB", "ABC");

    return 0;
}
