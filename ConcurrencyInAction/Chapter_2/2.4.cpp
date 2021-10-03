#include <algorithm>
#include <iostream>
#include <numeric>
#include <thread>
#include <vector>

template <typename Iterator, typename T>
struct accumulate_block
{
    void operator()(Iterator first, Iterator last, T& result)
    {
        result = std::accumulate(first, last, result);
    }
};

template <typename Iterator, typename T>
T parallel_accumulate(Iterator first, Iterator last, T init)
{
    const auto length = std::distance(first, last);

    if (!length)
    {
        return init;
    }

    const auto hardware_threads = std::thread::hardware_concurrency();
    const decltype(hardware_threads) min_per_thread = 25;
    const decltype(hardware_threads) max_threads = (length + min_per_thread - 1) / min_per_thread;
    const decltype(hardware_threads) num_threads = std::min(hardware_threads != 0 ? hardware_threads : 2, max_threads);

    const auto block_size = length / num_threads;

    std::vector<T> results(num_threads);
    std::vector<std::thread> threads(num_threads - 1); // -1 because of the exsistance of main thread

    Iterator block_start = first;
    for (size_t i = 0; i < (num_threads - 1); ++i)
    {
        Iterator block_end = block_start;
        std::advance(block_end, block_size);
        threads[i] = std::thread(accumulate_block<Iterator, T>(), block_start, block_end, std::ref(results[i]));
        block_start = block_end;
    }

    accumulate_block<Iterator, T>()(block_start, last, results[num_threads - 1]);

    /*
    for (auto& entry : threads)
    {
        entry.join();
    }
    */

    std::for_each(threads.begin(), threads.end(), [](std::thread& t) { t.join(); });

    return std::accumulate(results.begin(), results.end(), init);
}

int main()
{
    std::vector<int> a(100, 11);
    std::cout << "result: " << parallel_accumulate(a.begin(), a.end(), 0);

    return 0;
}
