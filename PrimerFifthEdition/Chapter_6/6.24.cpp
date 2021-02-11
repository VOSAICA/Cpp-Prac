#include <iostream>

using std::cout;

void print(const int ia[10]) // ia还是const *int，不管是传const int ia[100]还是const int ia[1]都可以，所以会越界
{                            // 应该const int (&ia)[10]
    for (size_t i = 0; i != 10; ++i)
        cout << ia[i] << '\n';
}

int main()
{
    int ia[4]{9, 2, 3, 6};

    print(ia);

    return 0;
}
