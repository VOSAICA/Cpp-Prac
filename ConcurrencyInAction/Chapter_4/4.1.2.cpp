#include <condition_variable>
#include <memory>
#include <mutex>
#include <queue>

template <typename T>
class threadsafe_queue
{
public:
    threadsafe_queue() = default;

    threadsafe_queue(const threadsafe_queue& other)
    {
        std::lock_guard<std::mutex> lk(other.mut);
        data_queue = other.data_queue;
    }

    threadsafe_queue& operator=(const threadsafe_queue&) = delete;

    void push(T new_value)
    {
        std::lock_guard<std::mutex> lk(mut);
        data_queue.push(new_value);
        data_cond.notify_one();
    }

    bool try_pop(T& value)
    {
        std::lock_guard<std::mutex> lk(mut);
        if (data_queue.empty())
        {
            return false;
        }
        value = data_queue.front();
        data_queue.pop();
        return true;
    }

    std::shared_ptr<T> try_pop()
    {
        std::lock_guard<std::mutex> lk(mut);
        if (data_queue.empty())
        {
            return std::shared_ptr<T>();
        }
        std::shared_ptr<T> res(std::make_shared<T>(data_queue.front()));
        data_queue.pop();
        return res;
    }

    void wait_and_pop(T& value)
    {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk, [this] { return !data_queue.empty(); });
        value = data_queue.front();
        data_queue.pop();
    }

    std::shared_ptr<T> wait_and_pop()
    {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk, [this] { return !data_queue.empty(); });
        std::shared_ptr<T> res(std::make_shared<T>(data_queue.frond()));
        data_queue.pop();
        return res;
    }

    [[nodiscard]] bool empty() const
    {
        std::lock_guard<std::mutex> lk(mut);
        return data_queue.empty();
    }

private:
    mutable std::mutex mut;
    std::queue<T> data_queue;
    std::condition_variable data_cond;
};

#include <iostream>

int main()
{
    threadsafe_queue<int> a;

    std::thread t1(&threadsafe_queue<int>::push, &a, 3); // 有函数重载时不能指定指针指向的函数
    std::thread t2([&]() { a.push(3); });                // 用lambda可以避免，貌似static_cast也行
    t1.join();
    t2.join();

    int temp = -1;
    std::thread t3{[&]() { a.try_pop(); }};
    t3.join();

    std::thread t4{[&](int& t) { a.try_pop(t); }, std::ref(temp)};
    // std::thread t4{[&]() { a.try_pop(temp); }}; 同样
    t4.join();

    std::cout << a.empty() << std::endl;
    std::cout << temp;

    return 0;
}
