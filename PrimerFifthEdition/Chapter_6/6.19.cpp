#include <string>
#include <vector>

using std::string;
using std::vector;

double calc(double);

int count(const string &, char);

int sum(vector<int>::iterator, vector<int>::iterator, int);

int main()
{
    calc(23.4, 55.1); //参数多了

    count("abcda", 'a');

    calc(66);

    vector<int> vec(10);
    sum(vec.begin(), vec.end(), 3.8);

    return 0;
}
