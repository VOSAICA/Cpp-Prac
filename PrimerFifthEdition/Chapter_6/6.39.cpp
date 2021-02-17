int calc(int, int)
{
    return 1;
}
int calc(const int, const int)
{
    return 3;
} // 重复定义，顶层const无区别

int get();
double get(); // 无法重载仅按返回类型区分的函数

int* reset(int*);
double* reset(double*);
