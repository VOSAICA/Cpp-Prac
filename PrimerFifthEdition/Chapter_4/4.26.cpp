#include <iostream>

using std::cout;

int main()
{
    unsigned int quiz1 = 0;
    quiz1 |= 1U << 27;    // 学生27通过测试
    quiz1 &= ~(1U << 27); //学生27没通过测试

    bool status27 = quiz1 & (1U << 27);
    cout << status27;

    return 0;
}
