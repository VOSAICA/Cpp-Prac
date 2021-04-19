#include <cstring>
#include <iostream>
#include <memory>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::unique_ptr;

int main()
{
    size_t max = 5;
    auto p = new string[max]();
    size_t index = 0;

    string temp;
    while (cin >> temp)
    {
        if (index >= max)
        {
            max *= 2;
            auto np = new string[max]();
            for (size_t i = 0; i < index; ++i)
            {
                *(np + i) = *(p + i);
            }
            delete[] p;
            p = np;
        }
        *(p + index++) = temp;
    }

    for (size_t i = 0; i < index; ++i)
    {
        cout << *(p + i) << ' ';
    }
    delete[] p;

    return 0;
}
