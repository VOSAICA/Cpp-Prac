#include <iostream>
#include <map>
#include <string>

using std::cout;
using std::multimap;
using std::string;

int main()
{
    multimap<string, string> archive;
    archive.emplace("Cinder", "Cursed Unkindled");
    archive.emplace("Arthur", "Apple and Its Seed");
    archive.emplace("Bell", "Badminton and Shit");

    for (auto& i : archive)
        cout << i.first << ": " << i.second << '\n';

    return 0;
}
