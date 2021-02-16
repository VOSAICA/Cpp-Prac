#include <iostream>

using std::cout;
using std::string;

string make_plural(size_t ctr, const string& word, const string& ending = "s")
{
    return (ctr > 1) ? word + ending : word;
}

int main()
{
    cout << make_plural(1, "success", "es") << '\n';
    cout << make_plural(2, "success", "es") << '\n';
    cout << make_plural(1, "failure", "s") << '\n';
    cout << make_plural(2, "failure", "s");

    return 0;
}
