template <typename T>
void f(T);

template <typename T>
void f(const T*);

template <typename T>
void g(T);

template <typename T>
void g(T*);

int i = 42;
int* p = &i;
const int ci = 0;
const int* p2 = &ci;

int main()
{
    g(42); // g(T)
    g(p);  // g(T*)
    g(ci); // g(T)
    g(p2); // g(T*)
    f(42); // f(T)
    f(p);  // f(T)
    f(ci); // f(T)
    f(p2); // f(const T*)

    return 0;
}
