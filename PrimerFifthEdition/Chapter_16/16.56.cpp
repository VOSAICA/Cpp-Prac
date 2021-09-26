#include <iostream>
#include <sstream>

template <typename T>
std::string debug_rep(const T& t)
{
    std::ostringstream ret;
    ret << t;
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

template <typename... Args>
std::ostream& errorMsg(std::ostream& os, const Args&... rest)
{
    // return print(os, debug_rep(a1), debug_rep(a2), ..., debug_rep(aN));
    return print(os, debug_rep(rest)...);
}

int main()
{
    errorMsg(std::cout, 2, 1);

    return 0;
}
