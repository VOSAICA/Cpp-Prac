#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vi;
    for (int i = 1; i <= 5; i++)
    {
        vi.push_back(i);
    }

    for (vector<int>::iterator it = vi.begin(); it != vi.end(); it++)
    {
        cout << *it << endl;
    }

    return 0;
}
