int main()
{
    int a, b;
    int* ptr_a = &a;
    int* ptr_b = &b;

    int* ptr = ptr_a + ptr_b; // int*与 int*之间没有+运算符的定义
    // 有指针之间相减表示距离，相加没啥意义

    return 0;
}
