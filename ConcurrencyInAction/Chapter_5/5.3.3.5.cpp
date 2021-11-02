#include <atomic>
#include <cassert>
#include <string>
#include <thread>

struct X
{
    int i;
    std::string s;
};

std::atomic<X*> p{nullptr};
std::atomic<int> a{0};

void create_x()
{
    X* x = new X;
    x->i = 42;
    x->s = "hello";
    a.store(99, std::memory_order_relaxed); // 1
    p.store(x, std::memory_order_release);  // 2
    // 可以用std::kill_dependency来打破依赖
}

void use_x()
{
    X* x;
    while ((x = p.load(std::memory_order_consume)) == nullptr) // 3
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    assert(x->i == 42);                              // 4 不会触发
    assert(x->s == "hello");                         // 5 不会触发
    assert(a.load(std::memory_order_relaxed) == 99); // 6 可能触发
}

int main()
{
    std::thread t1(create_x);
    std::thread t2(use_x);
    t1.join();
    t2.join();

    delete p;

    return 0;
}
