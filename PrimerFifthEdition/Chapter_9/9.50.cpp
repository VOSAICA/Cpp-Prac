#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

int main()
{
    int sum = 0;
    vector<string> vec{"123", "-123", "246a"};
    for (auto i : vec)
        sum += std::stof(i);

    cout << sum;

    return 0;
}
