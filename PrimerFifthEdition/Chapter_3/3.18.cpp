#include <vector>
using std::vector;

int main()
{
    vector<int> ivec;
    // ivec[0] = 42; 不能将下标用于添加元素
    ivec.emplace_back(42);

    return 0;
}
