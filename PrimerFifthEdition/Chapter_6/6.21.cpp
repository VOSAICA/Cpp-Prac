#include <iostream>

using std::cout;

int larger(const int& a, int* const& b) // 对指向const int的指针的引用
{
    return a > *b ? a : *b;
}

int main()
{
    int a = 10, b = 11;
    int* c = &b;
    cout << larger(a, c);

    return 0;
}
