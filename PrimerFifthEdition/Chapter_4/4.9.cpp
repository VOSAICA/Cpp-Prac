#include <iostream>

const char* cp = "Hello World";

int main()
{
    if (cp && *cp) // 先计算指针cp是否不为0，然后计算*cp的值
        std::cout << "ok";

    return 0;
}
