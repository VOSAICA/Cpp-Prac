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

    my_thread.join();

    return 0;
}
