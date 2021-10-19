#include <future>
#include <iostream>

int findTheAnswerToLTUaE()
{
    int ans = 0;
    for (int i = 0; i < 42; ++i)
    {
        ++ans;
    }
    return ans;
}

void doOtherStuff()
{
    for (int i = 0; i < 42; ++i)
    {
        std::cout << "..";
    }
}

int main()
{
    std::future<int> theAnswer = std::async(findTheAnswerToLTUaE);
    doOtherStuff();
    std::cout << "The answer is " << theAnswer.get() << std::endl;

    auto f1 = std::async(std::launch::deferred, findTheAnswerToLTUaE); // 被推迟到wait()或者get()才运行
    auto f2 = std::async(std::launch::async, findTheAnswerToLTUaE);    // 在独立线程运行（默认模式）
    auto f3 = std::async(std::launch::deferred | std::launch::async, []() { std::cout << "deferred | async\n"; });
    std::cout << f2.get();

    return 0;
}
