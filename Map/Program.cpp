#include<iostream>
#include<map>
using namespace std;

int main()
{
    map<char, int> mp;
    mp['c'] = 20;
    mp['c'] = 30;

    cout << mp['c'] << endl;
    for(map<char, int>::iterator it = mp.begin(); it != mp.end(); it++)
    {
        printf("%c %d\n", it -> first, it -> second);
    }

    return 0;
}
