#include <iostream>
using namespace std;

void swap2(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap3(int &a, int &b) //引用， 与指针不同
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 1234;
    int *p = &a;

    cout << p << endl;
    cout << *p << endl;

    *p = 3456;
    cout << a << endl;

    string b = "asdf";
    string *q = &b;

    cout << *q << endl;

    int c[3] = {2, 1, 0};
    int *start = c;
    cout << *start << endl;
    start = &c[1];

    int d = 20, e = 10;
    int *g = &d, *h = &e;

    swap2(g, h);

    cout << d << " " << e << endl;

    swap3(d, e);

    cout << d << " " << e << endl;
    return 0;
}