#include <vector>

template <typename It>
auto fcn3(It beg, It end) -> decltype(*beg + 0) // 只有支持+0的类型才ok
{
    return *beg;
}

int main()
{
    std::vector<int> a{0, 1, 2, 3};

    auto b = fcn3(a.begin(), a.end()); // 返回int

    return 0;
}
