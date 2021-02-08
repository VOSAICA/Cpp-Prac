#include <iostream>

using std::cerr;
using std::cin;
using std::cout;
using std::runtime_error;

int main()
{
    double a, b;

    while (cin >> a >> b)
    {
        try
        {
            if (b == 0)
                throw runtime_error("Divider must not be 0");
            cout << a / b << '\n';
        }
        catch (runtime_error e)
        {
            cerr << e.what() << '\n';
            cout << "Type again? Enter y/n" << '\n';

            char answer;
            cin >> answer;

            if (answer == 'y')
                continue;
            else
                break;
        }
    }

    return 0;
}
