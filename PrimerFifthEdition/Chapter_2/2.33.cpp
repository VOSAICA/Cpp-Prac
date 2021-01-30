typedef char *pstring; //其实是typedef char* pstring;
using pstring = char *;

int main()
{
    int i = 0, &r = i;
    const int ci = i, &cr = ci;

    auto a = r;        //a是int
    auto b = ci;       //b是int，忽略顶层const
    auto c = cr;       //c是int，忽略引用，然后忽略顶层const
    auto d = &i;       //int *
    auto e = &ci;      //const int *，底层const保留
    const auto f = ci; //const int
    auto &g = ci;      //对const int的引用

    a = 42;
    b = 42;
    c = 42;
    d = 42;
    e = 42;
    g = 42;

    return 0;
}
