#include <iostream>
#include <mutex>
#include <thread>

struct SomeObject
{
    int a;
    int b;
    int c;

    SomeObject(const int& x, const int& y, const int& z) : a(x), b(y), c(z)
    {
    }
};

inline void swap(SomeObject& lhs, SomeObject& rhs)
{
    using std::swap;

    swap(lhs.a, rhs.a);
    swap(lhs.b, rhs.b);
    swap(lhs.c, rhs.c);
}

class X
{
private:
    SomeObject detail;
    std::mutex m;

public:
    X(const SomeObject& so) : detail(so)
    {
    }

    inline friend void swap(X& lhs, X& rhs);
};

inline void swap(X& lhs, X& rhs)
{
    using std::swap;

    if (&lhs == &rhs)
    {
        return;
    }
    std::unique_lock<std::mutex> lockA(lhs.m, std::defer_lock); // 用defer_lock表示构造时不上锁
    std::unique_lock<std::mutex> lockB(rhs.m, std::defer_lock);
    std::lock(lockA, lockB);

    swap(lhs.detail, rhs.detail);
}

int main()
{
    X a(SomeObject(2, 5, 7));
    X b(SomeObject(1, 3, 4));

    swap(a, b);

    return 0;
}
