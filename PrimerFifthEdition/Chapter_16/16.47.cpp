#include <iostream>
#include <string>

template <typename F, typename T1, typename T2>
void call(F f, T1&& t1, T2&& t2)
{
    f(std::forward<T1>(t1), std::forward<T2>(t2));
}

void f(std::string&& a, std::string& b)
{
    std::string c(std::move(b));
    c.append(".");

    std::cout << a << " " << c;
}

int main()
{
    std::string a = "sb";
    call(f, "Hello", a);

    std::cout << a;

    return 0;
}
