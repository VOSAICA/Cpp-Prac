const int i = 42;
auto j = i;                 //int
const auto &k = i;          //对const int的引用
auto *p = &i;               //const int *
const auto j2 = i, &k2 = i; //const int, 对const int的引用
