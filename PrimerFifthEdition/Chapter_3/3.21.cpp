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

    // std::vector<int>::iterator it;
    for (auto it = v1.begin(); it != v1.end(); ++it)
        cout << *it << ' ';
    cout << '\n';
    for (auto it = v2.begin(); it != v2.end(); ++it)
        cout << *it << ' ';
    cout << '\n';
    for (auto it = v3.begin(); it != v3.end(); ++it)
        cout << *it << ' ';
    cout << '\n';
    for (auto it = v4.begin(); it != v4.end(); ++it)
        cout << *it << ' ';
    cout << '\n';
    for (auto it = v5.begin(); it != v5.end(); ++it)
        cout << *it << ' ';
    cout << '\n';

    // std::string::iterator it;
    for (auto it = v6.begin(); it != v6.end(); ++it)
        cout << *it << ' ';
    cout << '\n';
    for (auto it = v7.begin(); it != v7.end(); ++it)
        cout << *it << ' ';

    return 0;
}
