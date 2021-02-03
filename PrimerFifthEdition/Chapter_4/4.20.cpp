#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

int main()
{
    vector<string> valstr{"abby", "abel", "ahab"};
    auto iter = valstr.begin();

    cout << *iter++;
    cout << (*iter)++; //string++
    cout << (*iter).empty();
    cout << iter->empty();   //和上一行一样
    cout << ++*iter;         //++string
    cout << iter++->empty(); // string.empty()

    return 0;
}
