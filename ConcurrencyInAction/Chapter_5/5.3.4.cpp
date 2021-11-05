#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

std::vector<int> queue_data;
std::atomic<int> count;

void populate_queue()
{
    unsigned const number_of_items = 20;
    queue_data.clear();
    for (unsigned i = 0; i < number_of_items; ++i)
    {
        queue_data.push_back(static_cast<int>(i));
    }

    count.store(number_of_items, std::memory_order_release);
}

void consume_queue_items()
{
    while (true)
    {
        int item_index;
        // store()会与标记为memory_order_release的每个操作同步
        // 第二个fetch_sub()可见第一个fetch_sub的操作
        if ((item_index = count.fetch_sub(1, std::memory_order_acquire)) <= 0)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            continue;
        }
        std::cout << std::this_thread::get_id() << ": " << (queue_data[item_index - 1]) << std::endl;
    }
}

int main()
{
    std::thread a(populate_queue);
    std::thread b(consume_queue_items);
    std::thread c(consume_queue_items);

    a.join();
    b.join();
    c.join();

    return 0;
}
