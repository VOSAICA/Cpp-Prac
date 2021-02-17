#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

int main()
{
    vector<int> v1;              // 空
    vector<int> v2(10);          // 十个0
    vector<int> v3(10, 42);      // 十个42
    vector<int> v4{10};          // 10
    vector<int> v5{10, 42};      // 10 42
    vector<string> v6{10};       // 十个""
    vector<string> v7{10, "hi"}; // 十个"hi"

    for (auto a : v1)
        cout << a << ' ';
    cout << '\n';
    for (auto a : v2)
        cout << a << ' ';
    cout << '\n';
    for (auto a : v3)
        cout << a << ' ';
    cout << '\n';
    for (auto a : v4)
        cout << a << ' ';
    cout << '\n';
    for (auto a : v5)
        cout << a << ' ';
    cout << '\n';
    for (auto a : v6)
        cout << a << ' ';
    cout << '\n';
    for (auto a : v7)
        cout << a << ' ';

    return 0;
}
