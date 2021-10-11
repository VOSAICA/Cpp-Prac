#include <mutex>
#include <thread>

void prepareData()
{
}

void doSomething()
{
}

std::unique_lock<std::mutex> get_lock()
{
    extern std::mutex someMutex;
    std::unique_lock<std::mutex> lk(someMutex);
    prepareData();
    return lk;
} // lk被移动

void process_data()
{
    std::unique_lock<std::mutex> lk(get_lock());
    doSomething();

    lk.unlock(); // 提前放弃锁，让其他函数可以访问数据
} // lk被销毁

std::mutex someMutex;

int main()
{
    return 0;
}
