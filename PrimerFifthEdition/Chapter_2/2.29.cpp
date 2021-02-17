int i, *const cp;      // 常量未初始化
int *p1, *const p2;    // 常量未初始化
const int ic, &r = ic; // 常量未初始化
const int* const p3;   // 常量未初始化
const int* p;

int main()
{
    i = ic;
    p1 = p3;
    p1 = &ic;
    p3 = &ic;
    p2 = p1;
    ic = *p3;

    return 0;
}
