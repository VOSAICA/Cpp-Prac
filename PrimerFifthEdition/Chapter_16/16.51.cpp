#include <iostream>

template <typename T, typename... Args>   // Args为类型参数
void foo(const T& t, const Args&... rest) // rest为函数参数
{
    std::cout << sizeof...(Args) << '\n';
    std::cout << sizeof...(rest) << '\n';
}

int main()
{
    foo(1, 2);
    foo(1, 23, 4, 5, 6);

    return 0;
}
