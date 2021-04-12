#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::istringstream;
using std::map;
using std::runtime_error;
using std::string;

map<string, string> buildMap(ifstream& map_file)
{
    map<string, string> trans_map;
    string key;
    string value;
    while (map_file >> key && getline(map_file, value))
    {
        if (value.size() > 1)
            trans_map[key] = value.substr(1);
        else
            throw runtime_error("no rule for " + key);
    }
    return trans_map;
}

const string& transform(const string& s, const map<string, string>& m)
{
    auto map_it = m.find(s);
    if (map_it != m.cend())
        return map_it->second;
    else
        return s;
}

void word_transform(ifstream& map_file, ifstream& input)
{
    auto trans_map = buildMap(map_file);
    string text;
    while (getline(input, text))
    {
        istringstream stream(text);
        string word;
        bool firstword = true;
        while (stream >> word)
        {
            if (firstword)
                firstword = false;
            else
                cout << " ";
            cout << transform(word, trans_map);
        }
        cout << endl;
    }
}

int main()
{
    auto map = ifstream("11.33_Map.txt");
    auto words = ifstream("11.33_Words.txt");

    word_transform(map, words);

    return 0;
}
