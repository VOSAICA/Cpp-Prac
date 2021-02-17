#include <iostream>

using std::cout;

int main()
{
    int ival = 3.54 + 3;
    float fval = 0.0f;
    char cval = 'a';

    if (fval) // float 到 bool
        cout << "ok";

    double dval = fval + ival; //都到double

    auto whatSoEver = dval + ival * cval; // char先到int相乘，然后转换为double

    return 0;
}
