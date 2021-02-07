#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

const vector<string> Scores{"F", "D", "C", "B", "A", "A+"};

int main()
{
    string lettergrade;
    int numbergrade;

    cin >> numbergrade;

    lettergrade = (numbergrade < 60 ? Scores[0] : Scores[(numbergrade - 50) / 10]);

    cout << lettergrade;

    return 0;
}
