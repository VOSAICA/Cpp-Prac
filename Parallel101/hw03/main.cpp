#include <algorithm>
#include <iostream>
#include <variant>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> const& a)
{
    os << "{";
    for (size_t i{0}; i < a.size() - 1; ++i)
    {
        os << a[i] << ", ";
    }
    os << a.back() << "}";
    return os;
}

template <class T1, class T2>
auto operator+(const std::vector<T1>& a, const std::vector<T2>& b)
{
    using T0 = decltype(T1{} + T2{});
    auto minSize{std::min(a.size(), b.size())};

    std::vector<T0> c{};
    c.reserve(minSize);
    for (size_t i{0}; i < minSize; ++i)
    {
        c.emplace_back(a[i] + b[i]);
    }
    return c;
}

template <class T1, class T2>
auto operator+(std::variant<T1, T2> const& a, std::variant<T1, T2> const& b)
{
    return std::visit([](auto const& v1, auto const& v2) -> std::variant<T1, T2> { return v1 + v2; }, a, b);
}

template <class T1, class T2>
std::ostream& operator<<(std::ostream& os, std::variant<T1, T2> const& a)
{
    std::visit([&](auto const& v) { os << v; }, a);
    return os;
}

int main()
{
    std::vector<int> a{1, 4, 2, 8, 5, 7};
    std::cout << a << std::endl;
    std::vector<double> b{3.14, 2.718, 0.618};
    std::cout << b << std::endl;
    auto c{a + b};

    // 应该输出 1
    std::cout << std::is_same_v<decltype(c), std::vector<double>> << std::endl;

    // 应该输出 {4.14, 6.718, 2.618}
    std::cout << c << std::endl;

    std::variant<std::vector<int>, std::vector<double>> d{c};
    std::variant<std::vector<int>, std::vector<double>> e{a};
    d = d + std::variant<std::vector<int>, std::vector<double>>{c} + e;

    // 应该输出 {9.28, 17.436, 7.236}
    std::cout << d << std::endl;

    return 0;
}
