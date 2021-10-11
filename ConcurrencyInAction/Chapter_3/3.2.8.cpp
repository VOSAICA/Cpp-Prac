#include <mutex>
#include <thread>

class Y
{
private:
    int someDetail;
    mutable std::mutex m;
    int getDetail() const
    {
        std::lock_guard<std::mutex> lock_a(m);
        return someDetail;
    }

public:
    Y(int sd) : someDetail(sd)
    {
    }

    friend bool operator==(const Y& lhs, const Y& rhs)
    {
        if (&lhs == &rhs)
        {
            return true;
        }
        const int lhsValue = lhs.getDetail(); // 这行执行完后已经不持有锁，别的线程可以访问lhs了
        const int rhsValue = rhs.getDetail(); // 但是在这行读取时，lhs可能已经被改变了

        return lhsValue == rhsValue; // 即使两个值在任意一个瞬间没有相等过，依旧有可能返回true
    }
};
