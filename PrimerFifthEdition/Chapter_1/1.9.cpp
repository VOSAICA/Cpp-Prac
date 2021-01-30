#include <iostream>

int main()
{
    int i = 50, sum = 0;
    while (i <= 100)
    {
        sum += i;
        ++i;
        //++i是左值，效率高一扣扣,另外
        //int i = 3;
        //return i++, 返回3
        //return ++i, 返回4
    }
    std::cout << sum;
    return 0;
}
