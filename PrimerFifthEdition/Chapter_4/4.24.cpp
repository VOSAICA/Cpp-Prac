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
    //左结合律就会先算grade >= 90，不过条件运算符满足右结合律

    return 0;
}
