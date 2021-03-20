#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

class date
{
public:
    date(string str)
    {
        string::size_type yearEnd, monthEnd;
        if (str.find('/') == string::npos)
        {
            yearEnd = str.find_first_of(" ");
            monthEnd = str.find_last_of(" ");
        }
        else
        {
            yearEnd = str.find_first_of("/");
            monthEnd = str.find_last_of("/");
        }
        auto strYear = str.substr(0, yearEnd);
        auto strMonth = str.substr(yearEnd + 1, monthEnd);
        auto strDay = str.substr(monthEnd + 1, str.size());

        year = std::stoi(strYear);
        month = std::stoi(strMonth);
        day = std::stoi(strDay);
    }
    unsigned year, month, day;
};

int main()
{
    date a("2002/12/16");
    cout << a.year << '\n';
    cout << a.month << '\n';
    cout << a.day << '\n';

    date b("2000 9 11");
    cout << b.year << '\n';
    cout << b.month << '\n';
    cout << b.day << '\n';

    return 0;
}
