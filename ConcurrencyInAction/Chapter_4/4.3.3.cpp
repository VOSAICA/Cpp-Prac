#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <ostream>
#include <thread>

using namespace std::chrono_literals;

std::condition_variable cv;
bool done = false;
std::mutex m;

bool wait_loop()
{
    auto const timeout = std::chrono::steady_clock::now() + std::chrono::milliseconds(500);
    std::unique_lock<std::mutex> lk(m);

    while (!done)
    {
        // wait_until检查时间，不满足时解锁lk，把线程置于阻塞。满足时返回。被notify时从睡眠醒来，获取锁
        if (cv.wait_until(lk, timeout) == std::cv_status::timeout)
        {
            break;
        }
    }
    return done;
}

int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(2s);
    auto stop = std::chrono::high_resolution_clock::now();

    auto dura = stop - start;
    std::cout << "Hello, " << std::chrono::duration_cast<std::chrono::milliseconds>(dura).count() << " milliseconds"
              << std::endl;

    return 0;
}
