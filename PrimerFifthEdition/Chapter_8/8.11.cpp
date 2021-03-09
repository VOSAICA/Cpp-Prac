#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::istringstream;
using std::string;
using std::vector;

struct PersonInfo
{
    string name;
    vector<string> phones;
};

int main()
{
    string line, word;
    vector<PersonInfo> people;
    istringstream record;

    while (getline(cin, line))
    {
        PersonInfo info;
        record.str(line);
        record.clear(); // 把istringstream定义在while循环之外的话，record.good不会被重置，得用clear()
        record >> info.name;
        while (record >> word)
        {
            info.phones.push_back(word);
        }
        people.push_back(info);
    }

    for (auto i : people)
    {
        cout << i.name << ' ';
        for (auto j : i.phones)
        {
            cout << j << ' ';
        }
        cout << endl;
    }

    return 0;
}
