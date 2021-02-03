#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main()
{
    int grade;
    string finalgrade;

    while (cin >> grade)
        cout << (finalgrade = (grade >= 90) ? "high pass" : (grade >= 75) ? "pass" : (grade >= 60) ? "low pass" : "fail");

    while (cin >> grade)
        if (grade >= 90)
            cout << "high pass";
        else if (grade >= 75)
            cout << "pass";
        else if (grade >= 60)
            cout << "low pass";
        else
            cout << "fail";

    return 0;
}
