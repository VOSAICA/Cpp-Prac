int main()
{
    int a = 3, b = 4;
    decltype(a) c = a;
    decltype((b)) d = a;
    ++c; // 4
    ++d; // 4, a也变成4

    return 0;
}
