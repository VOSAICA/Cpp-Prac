#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

const char* foo()
{
    return "abcde";
}

int main()
{
    const char* a = "abcde";
    vector<const char*> roster1(3, a);
    vector<const char*> roster2{3, foo()};

    cout << std::equal(
        roster1.cbegin(), roster1.cend(),
        roster2.cbegin()); // 这里只会比较const char*的地址，但好像内容相同的C风格字符串会指向同一个地址，总之不这么写就完了

    return 0;
}
