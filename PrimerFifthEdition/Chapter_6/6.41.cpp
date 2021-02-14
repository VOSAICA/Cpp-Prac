char *init(int ht, int wd = 80, char bckgrnd = ' ');

int main()
{
    init(); //没有ht
    init(24, 10);
    init(14, '*'); //char被转换成int然后初始化wd了

    return 0;
}
