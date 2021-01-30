int main()
{
    int a = 3;
    const int b = a;

    auto c1 = b;        //int
    decltype(b) c2 = b; //const int

    auto d1 = &b;         //const int *
    decltype(&b) d2 = &b; //const int *

    return 0;
}
