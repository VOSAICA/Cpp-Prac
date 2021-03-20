#include <deque>
#include <iostream>
#include <stack>

using std::cin;
using std::cout;
using std::deque;
using std::stack;

int main()
{
    stack<char> express;
    char str;

    while (cin >> str)
    {
        express.emplace(str);
        if (str == ')')
        {
            express.pop();
            deque<char> shortExpress;
            do
            {
                shortExpress.emplace_front(express.top());
                express.pop();
            } while (express.top() != '(');
            express.pop();

            for (auto i : shortExpress)
                express.push(i);
        }
    }

    while (!express.empty())
    {
        cout << express.top();
        express.pop();
    }

    return 0;
}
// 5x(3+8)-9
