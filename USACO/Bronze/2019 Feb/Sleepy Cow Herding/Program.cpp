#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int a, b, c;
    ifstream in;
    in.open("herding.in");
    in >> a >> b >> c;
    if (a > c)
        swap(a, c);
    if (a > b)
        swap(a, b);
    if (b > c)
        swap(b, c);

    ofstream out;
    out.open("herding.out");

    if (a + 2 == c)
    {
        out << 0 << endl;
    }
    else if (a + 2 == b || b + 2 == c)
    {
        out << 1 << endl;
    }
    else
    {
        out << 2 << endl;
    }

    if ((b - a - 1) > (c - b - 1))
    {
        out << b - a - 1 << endl;
    }
    else
    {
        out << c - b - 1 << endl;
    }

    return 0;
}