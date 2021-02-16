//(a)
int calc(int&, int&);
int calc(const int&, const int&);

//(b)
int calc(char*, char*);
int calc(const char*, const char*);

//(c)
int calc(char*, char*);
int calc(char* const, char* const); // 顶层const被忽略，重复定义calc(char *, char *)
