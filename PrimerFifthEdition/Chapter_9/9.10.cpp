#include <vector>

using std::vector;

vector<int> v1;         // vector<int>
const vector<int> v2;   // const vector<int>
auto it1 = v1.begin();  // vector<int>::iterator
auto it2 = v2.begin();  // vector<int>::const_iterator
auto it3 = v1.cbegin(); // vector<int>::const_iterator
auto it4 = v2.cbegin(); // vector<int>::const_iterator

int main()
{
    return 0;
}
