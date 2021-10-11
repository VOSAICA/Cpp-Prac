#include <iostream>
#include <list>
#include <mutex>
#include <thread>

std::list<int> myList;
std::mutex myMutex;

void add2List(int value)
{
    // std::lock_guard<std::mutex> guard(myMutex);
    std::lock_guard guard(myMutex); // C++17 类模板参数推导
    myList.push_back(value);
}

bool list_contains(int value)
{
    std::lock_guard<std::mutex> guard(myMutex);
    return std::find(myList.begin(), myList.end(), value) != myList.end();
}

int main()
{
    return 0;
}
