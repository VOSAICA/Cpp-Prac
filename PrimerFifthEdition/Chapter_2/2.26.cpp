const int buf; //未初始化
int cnt = 0;
const int sz = cnt;

int main()
{
    ++cnt;
    ++sz; //不能修改常量

    return 0;
}
