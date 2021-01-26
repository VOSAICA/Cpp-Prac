#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<unsigned> scores(11, 0);
    unsigned grade;
    decltype(scores.begin()) it;

    while (cin >> grade)
    {
        if (grade <= 100)
        {
            it = scores.begin() + grade / 10;
            ++*it;
        }
    }

    for (auto a : scores)
        cout << a << ' ';

    return 0;
}
