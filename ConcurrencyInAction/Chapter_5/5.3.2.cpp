#include <iostream>

void print(int a, int b) {
    std::cout << a << " " << b << std::endl;
}

int get_num()
{
    static int i = 0;
    return ++i;
}

int main()
{
    print(get_num(), get_num());

    return 0;
}
