unsigned buf_size = 1024;

int txt_size()
{
    return 0;
}

int ia1[buf_size]; //buf_size不是constexpr
int ia2[4 * 7 - 14];
int ia3[txt_size()];         //需要constexpr int txt_size();
char st[11] = "fundamental"; //字符串结尾为空字符'\0'
