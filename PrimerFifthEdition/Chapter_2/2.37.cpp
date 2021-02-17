int main()
{
    int a = 3, b = 4;
    decltype(a) c = a;     // int
    decltype(a = b) d = a; // &int, 赋值的表达式会产生引用，引用的类型是左值的类型

    return 0;
}
