#include <vector>

template <typename T>
void g(T&& val)
{
    std::vector<T> v;
}

int main()
{
    int a = 42;

    g(42); // T:int   val:int&& && collapsing to int&&  vector<int>
    g(a);  // T:int&  val:int& && collapsing to int&    vector<int&>

    return 0;
}
