#include <iostream>
#include <string>

using std::cout;
using std::string;

int main()
{
    string a("ab2c3d7R4E6"), numbers("0123456789");
    auto last = string::npos;

    for (decltype(a.size()) i = 0; i < a.size(); ++i)
        if (last != a.find_first_of(numbers, i) && a.find_first_not_of(numbers, i) != string::npos)
            cout << (last = a.find_first_of(numbers, i)) << '\n';
    cout << '\n';

    last = string::npos;
    for (decltype(a.size()) i = 0; i < a.size(); ++i)
        if (last != a.find_first_not_of(numbers, i) && a.find_first_not_of(numbers, i) != string::npos)
            cout << (last = a.find_first_not_of(numbers, i)) << '\n';

    return 0;
}
