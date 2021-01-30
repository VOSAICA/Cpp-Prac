int main()
{
    int ival = 1.01;
    int &rvall = 1.01; //初始值需要为左值
    int &rval2 = ival;
    int &rval3; //没有初始化

    return 0;
}
