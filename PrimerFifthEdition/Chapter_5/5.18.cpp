#include <iostream>

using std::cin;
using std::cout;

bool get_response() { return 0; }

int main()
{
    //(a)
    int a;
    do
    {
        int v1, v2;
        cout << "Please enter two numbers to sum:";
        if (cin >> v1 >> v2)
            cout << "Sum is: " << v1 + v2 << std::endl;
    } while (cin);

    //(b)
    int ival;
    do
    {
        //
    } while (ival = get_response());

    //(c)
    int ival2;
    do
    {
        ival2 = get_response();
    } while (ival2);

    return 0;
}
