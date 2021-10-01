#include <iostream>
#include <thread>

class background_task
{
public:
    void operator()() const
    {
        std::cout << "This is a background task\n";
    }

    ~background_task()
    {
        std::cout << "destroyed\n";
    }
};

class ThreadGuard
{
public:
    explicit ThreadGuard(std::thread& t) : thread(t)
    {
    }

    ThreadGuard(const ThreadGuard& tg) = delete;
    ThreadGuard& operator=(const ThreadGuard& tg) = delete;

    ~ThreadGuard()
    {
        if (thread.joinable())
        {
            thread.join();
            std::cout << "joined\n";
        }
    }

private:
    std::thread& thread;
};

int main()
{
    background_task f;
    std::thread my_thread(f);
    ThreadGuard tg(my_thread);

    return 0;
}
