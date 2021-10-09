#include <mutex>
#include <thread>

struct SomeObject
{
    int a;
    int b;
    int c;
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

    inline friend void swap(X& lhs, X& rhs)
    {
        using std::swap;

        if (&lhs == &rhs)
        {
            return;
        }
        /*
        std::lock(lhs.m, rhs.m);
        std::lock_guard lock_a(lhs.m, std::adopt_lock);
        std::lock_guard lock_b(rhs.m, std::adopt_lock);
        */

        // C++17
        std::scoped_lock guard(lhs.m, rhs.m);

        swap(lhs.detail, rhs.detail);
    }
};
