#include <iostream>

int main()
{
    std::cout << "Who goes with F\145rgus?\012"; // \145 stands for e, \012 stands for LF
    std::cout << 3.14e1L << std::endl;
    std::cout << 1024.f << std::endl;
    std::cout << 3.14L << std::endl;

    return 0;
}
