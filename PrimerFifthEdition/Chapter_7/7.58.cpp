#include <vector>

using std::vector;

class Example
{
public:
    static constexpr double rate = 6.5;
    static constexpr int vecSize = 20;
    static vector<double> vec; // 类内只能初始化整型类型的静态常量
};

constexpr double Example::rate;
vector<double> Example::vec(Example::vecSize);
