const int v2 = 0; //顶层const
int v1 = v2;      //不是const
int *p1 = &v1, &r1 = v1;
int i;
const int *p2 = &v2, *const p3 = &i, &r2 = v2; //p2是底层const, p3是顶层const
