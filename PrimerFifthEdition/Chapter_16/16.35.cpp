template <typename T>
T calc(T, int);

template <typename T>
T fcn(T, T);

double d;
float f;
char c;

int main()
{
    calc(c, 'c');
    calc(d, f);
    fcn(c, 'c');
    fcn(d, f); // 出现了唯二允许的转换之外的转换
}
