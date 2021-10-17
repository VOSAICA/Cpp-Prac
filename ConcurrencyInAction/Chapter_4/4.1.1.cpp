#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

using DataChunk = std::vector<int>;

std::mutex mut;
std::queue<DataChunk> dataQueue;
std::condition_variable dataCond;

void data_preparation_thread()
{
    while (more_data_to_prepare())
    {
        const DataChunk data = prepareData();
        {
            std::lock_guard<std::mutex> lk(mut); // 保护dataQueue
            dataQueue.push(data);
        }                      // mutex被解锁
        dataCond.notify_one(); // 通知等待线程
    }
}

void dataProcessingThread()
{
    while (true)
    {
        std::unique_lock<std::mutex> lk(mut); // 先锁上dataQueue
        // wait会检查dataQueue为非空，不满足时解锁dataQueue的lk，把线程置于阻塞。满足时返回。被notify时从睡眠醒来，获取锁，然后检查条件
        dataCond.wait(lk, [] { return !dataQueue.empty(); });
        DataChunk data = dataQueue.front();
        dataQueue.pop();
        lk.unlock();
        process(data);
        if (isLastChunk(data))
        {
            break;
        }
    }
}
