#include <exception>
#include <memory>
#include <mutex>
#include <stack>

struct Emptystack_error : std::exception
{
    [[nodiscard]] const char* what() const noexcept override
    {
        return "empty stack!";
    };
};

template <typename T>
class ThreadSafeStack
{
private:
    std::stack<T> data;
    mutable std::mutex m;

public:
    ThreadSafeStack() : data(std::stack<T>())
    {
    }

    ThreadSafeStack(const ThreadSafeStack& orgi)
    {
        std::lock_guard lock(orgi.m); // 拷贝过程中持有锁
        data = orgi.data();
    }

    ThreadSafeStack& operator=(const ThreadSafeStack& orgi) = delete;

    void push(T newVal)
    {
        std::lock_guard lock(m);
        data.push(std::move(newVal));
    }

    std::shared_ptr<T> pop()
    {
        std::lock_guard lock(m);
        if (data.empty())
        {
            throw Emptystack_error();
        }

        std::shared_ptr<T> res(std::make_shared<T>(std::move(data.top())));
        data.pop();
        return res;
    }

    void pop(T& val)
    {
        std::lock_guard lock(m);
        if (data.empty())
        {
            throw Emptystack_error();
        }
        val = std::move(data.top());
        data.pop();
    }

    bool empty() const
    {
        std::lock_guard lock(m);
        return data.empty();
    }
};

int main()
{
    ThreadSafeStack<int> tSStack;
    try
    {
        tSStack.push(8);
        tSStack.pop();
        tSStack.empty();
    }
    catch (Emptystack_error e)
    {
    }

    return 0;
}
