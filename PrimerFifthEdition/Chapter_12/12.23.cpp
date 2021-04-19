#include <cstring>
#include <iostream>
#include <memory>
#include <string>

using std::cout;
using std::string;
using std::unique_ptr;

int main()
{
    const char* a("SB");
    const char* b("NB");

    char c[strlen(a) + strlen(b) + 1];
    strcpy(c, a);
    strcat(c, b);

    unique_ptr<char[]> up(c);

    for (size_t i = 0; i < 100; ++i)
        cout << up[i];

    up.release();

    string d("SB");
    string e("NB");
    unique_ptr<string>(new string(d + e));

    return 0;
}
