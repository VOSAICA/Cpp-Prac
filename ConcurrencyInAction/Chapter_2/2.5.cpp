#include <iostream>
#include <thread>

std::thread::id masterThreadId;

void partOfAlgorithm()
{
    if (std::this_thread::get_id() == masterThreadId)
    {
        // do the main job
    }
    // do something else
    std::cout << std::this_thread::get_id() << std::endl;
}

int main()
{
    masterThreadId = std::this_thread::get_id();

    auto a = std::thread([]() { partOfAlgorithm(); });
    // std::cout << a.get_id();

    a.join();

    return 0;
}
