int main()
{
    extern int ix = 1024; //定义，不允许对外部变量的局部声明使用初始值设定项
    int iy;               //定义
    extern int iz;        //声明

    return 0;
}
