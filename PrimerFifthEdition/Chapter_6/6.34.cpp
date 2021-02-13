#include <iostream>

using std::cout;

int factorial(int val)
{
    if (val > 1) // 改成!=0会多算一个乘以1，碰到负val的时候还会停不下来
        return factorial(val - 1) * val;
    return 1;
}

int main()
{
    cout << factorial(4);

    return 0;
}
