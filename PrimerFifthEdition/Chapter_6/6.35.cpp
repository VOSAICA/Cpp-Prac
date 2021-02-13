#include <iostream>

using std::cout;

int factorial(int val)
{
    if (val > 1)
        return factorial(val--) * val; //后置递减返回之前的值，会变成死循环
    return 1;
}

int main()
{
    cout << factorial(4);

    return 0;
}
