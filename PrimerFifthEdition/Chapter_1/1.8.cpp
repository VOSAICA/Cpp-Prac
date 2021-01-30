#include <iostream>

//第一，二，四条是合法的
int main()
{
    std::cout << "/*";
    std::cout << "*/";
    std::cout << /* "*/" */;
    std::cout << /* "*/ " /* " /*" */;
    return 0;
}
