#include <iostream>

using std::cout;

int main()
{
    int j = 100, i = 19;

    double slope = static_cast<double>(j / i); //运算完整数除法再转换到double
    cout << slope;

    return 0;
}
