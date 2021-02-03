#include <iostream>

using std::cout;

struct foo
{
    int mem[4]{1, 2, 3, 4};
};

int f()
{
    return 1;
}

int main()
{
    int x = 1, y = 12, i = 1;
    int a, b = 4;
    foo bar;
    foo *p = &bar;

    cout << (sizeof x + y) << ' ';
    cout << ((sizeof x) + y) << '\n';

    cout << (sizeof p->mem[i]) << ' ';
    cout << (sizeof(p->mem[i])) << '\n';

    cout << (sizeof a < b) << ' ';
    cout << ((sizeof a) < b) << '\n';

    cout << (sizeof f()) << ' ';
    cout << (sizeof(f()));

    return 0;
}
