#include <iostream>
#include <sstream>
#include <string>

template <typename T>
std::string debug_rep(const T& t)
{
    std::ostringstream ret;
    ret << t << '\n';
    return ret.str();
}

template <typename T>
std::string debug_rep(T* p)
{
    std::ostringstream ret;
    ret << "pointer: " << p;
    if (p != nullptr)
    {
        ret << " " << debug_rep(*p);
    }
    else
    {
        ret << " null pointer";
    }
    return ret.str();
}

std::string debug_rep(const std::string& s)
{
    return '"' + s + '"';
}

std::string debug_rep(const char* p)
{
    return debug_rep(std::string(p));
}

int main()
{
    int a = 12;
    int* pa = &a;
    std::string s = "arst";

    std::cout << debug_rep(598351681);
    std::cout << debug_rep(pa);
    std::cout << debug_rep(s);

    return 0;
}
