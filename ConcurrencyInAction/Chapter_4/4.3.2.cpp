#include <chrono>
#include <future>
#include <iostream>
#include <ostream>

using namespace std::chrono_literals;

constexpr auto aDay = 24h;
constexpr auto halfHour = 30min;
constexpr auto aSecond = 1000ms;

int main()
{
    auto time1 = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::milliseconds(1000));
    std::cout << time1.count() << std::endl;

    std::future<int> f = std::async([]() { return 3; });
    // f.wait_for()超时会返回std::future_status::timeout，推迟则std::future_status::deferred
    if (f.wait_for(time1) == std::future_status::ready)
    {
        std::cout << f.get(); // 在time1内future没就绪则不会打印
    }

    return 0;
}
