/*
template <typename T, U, typename V> // U前面要跟typename
void f1(T, U, V);

template <typename T>
T f2(int& T); // T是个类型，int& T不知道是什么

inline template <typename T> // inline要在template的后面，返回类型的前面
T foo(T, unsigned int*);

template <typename T>
f4(T, T); // 没有返回值类型

using Ctype = char;
template <typename Ctype>
Ctype f5(Ctype a); // 要注意这里的Ctype并不是char
*/
