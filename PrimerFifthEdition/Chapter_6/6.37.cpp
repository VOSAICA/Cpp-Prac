#include <iostream>
#include <string>

using std::cout;
using std::string;

using string10_ref = string (&)[10];

string10_ref func1(string10_ref b)
{
    return b;
}

auto func2(string (&b)[10]) -> string (&)[10]
{
    return b;
} //我觉得尾置返回类比较好，方便

string a[10];
decltype(a)& func3(string (&b)[10])
{
    return b;
}

int main()
{
    string a = "abc";
    string b[10]{a + "d", a, a, a, a, a, a, a, a, a};
    string(&c)[10] = b;

    cout << *func1(c) << '\n';
    cout << *func2(c) << '\n';
    cout << *func3(c);

    return 0;
}
