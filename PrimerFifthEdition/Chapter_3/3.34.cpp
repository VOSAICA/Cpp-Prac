#include <iostream>
#include <vector>

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    auto p1 = std::begin(a);
    auto p2 = std::end(a);
    --p2;

    p1 += p2 - p1; // p1位移到p2所指向的地址，想要解引用的话p2不为尾指针
    std::cout << *p1;

    return 0;
}
