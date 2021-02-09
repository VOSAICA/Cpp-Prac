#include <iostream>

using std::cout;

int count()
{
    static int b = -1;
    return ++b;
}

int main()
{
    cout << count() << count() << count();

    return 0;
}
