#include <deque>
#include <future>
#include <iostream>
#include <mutex>
#include <thread>
#include <utility>

std::mutex m;
std::deque<std::packaged_task<void()>> tasks;

bool guiShutdown()
{
    return false;
}

// void getAndProcessGuiMessage();

void guiThread()
{
    while (!guiShutdown())
    {
        // getAndProcessGuiMessage();
        std::packaged_task<void()> task;
        {
            std::lock_guard<std::mutex> lk(m);
            if (tasks.empty())
            {
                continue;
            }
            task = std::move(tasks.front());
            tasks.pop_front();
        }
        task();
    }
}

template <typename Func>
std::future<void> postTaskForGuiThread(Func f)
{
    std::packaged_task<void()> task(f);
    std::future<void> res = task.get_future();
    std::lock_guard<std::mutex> lk(m);
    tasks.push_back(std::move(task));
    return res;
}

int main()
{
    std::thread guiBackGroundThread(guiThread);
    guiBackGroundThread.detach();
    postTaskForGuiThread([]() { std::cout << "Hello world\n"; });
    postTaskForGuiThread([]() { std::cout << "Hello Shi\n"; });
    // std::cout << postTaskForGuiThread([]() { return "abcd"; }).get();

    std::this_thread::sleep_for(std::chrono::seconds(1));
    guiShutdown();

    return 0;
}
