#include <functional>
#include <iostream>
#include <map>
#include <string>

using namespace std;

// 可以用函数指针，函数对象（定义了重载调用运算符的类），lambda来初始化
function<int(int, int)> add = plus<int>();
function<int(int, int)> subtract = minus<int>();
function<int(int, int)> multiply = multiplies<int>();
function<int(int, int)> divide = divides<int>();
function<int(int, int)> mod = modulus<int>();

map<string, function<int(int, int)>> binops = {{"+", add}, {"-", subtract}, {"*", multiply}, {"/", divide}, {"%", mod}};

int main()
{

    int a, b;
    string op;
    while (cin >> a >> op >> b)
    {
        cout << binops[op](a, b) << '\n';
    }

    return 0;
}
