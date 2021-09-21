#include <iostream>

template <typename T>
std::ostream& print(std::ostream& os, const T& t)
{
    return os << t;
}

template <typename T, typename... Args>
std::ostream& print(std::ostream& os, const T& t, const Args&... rest)
{
    os << t << " ";
    return print(os, rest...);
}

std::ostream& print(std::ostream& os, const int& i); // 好像什么都没有发生

int main()
{
    print(std::cout, "hello", "world", "magic number", 10.0, '.');

    return 0;
}
