#include <iostream>
#include <map>
#include <string>

using std::cout;
using std::multimap;
using std::string;

void remove(multimap<string, string>& m, const string& name)
{
    if (m.count(name) == 0)
        cout << "No key";
    else
        m.erase(name);
}

int main()
{
    multimap<string, string> archive;
    archive.emplace("Arthur", "Apple and Its Seed");
    archive.emplace("Bell", "Badminton and Shit");

    remove(archive, "Arthur");
    remove(archive, "Cinder");

    return 0;
}
