#include <iostream>
#include <thread>

class background_task
{
public:
    void operator()() const
    {
        std::cout << "This is a background task\n";
    }
};

int main()
{
    background_task f;
    std::thread my_thread(f);

    if (my_thread.joinable())
    {
        my_thread.join(); //等待
    }
    // my_thread.detach(); // 不等待

    return 0;
}
