#include <climits>
#include <iostream>
#include <mutex>
#include <stdexcept>
#include <thread>

class hierarchical_mutex
{
public:
    explicit hierarchical_mutex(unsigned long value) : hierarchy_value(value), previous_hierarchy_value(0)
    {
    }

    void lock()
    {
        check_for_hierarchy_violation();
        internal_mutex.lock();
        update_hierarchy_value();
    }

    void unlock()
    {
        if (this_thread_hierarchy_value != hierarchy_value)
        {
            throw std::logic_error("mutex hierarchy violated");
        }
        this_thread_hierarchy_value = previous_hierarchy_value;
        internal_mutex.unlock();
    }

    bool try_lock()
    {
        check_for_hierarchy_violation();
        if (!internal_mutex.try_lock())
        {
            return false;
        }
        update_hierarchy_value();
        return true;
    }

private:
    std::mutex internal_mutex;

    unsigned long const hierarchy_value;
    unsigned long previous_hierarchy_value;                        // 用于在unlock()时恢复层级值
    static thread_local unsigned long this_thread_hierarchy_value; // Storage class specifiers since C++11

    void check_for_hierarchy_violation() const
    {
        if (hierarchy_value >= this_thread_hierarchy_value)
        {
            throw std::logic_error("mutex hierarchy violated");
        }
    }

    void update_hierarchy_value()
    {
        previous_hierarchy_value = this_thread_hierarchy_value;
        this_thread_hierarchy_value = hierarchy_value;
    }
};

thread_local unsigned long hierarchical_mutex::this_thread_hierarchy_value(ULONG_MAX);

hierarchical_mutex highLevelMutex(10000);
hierarchical_mutex lowLevelMutex(5000);
hierarchical_mutex otherMutex(6000);

int doLowLevelStuff()
{
    return 1140;
}

int lowLevelFunc()
{
    std::lock_guard<hierarchical_mutex> lk(lowLevelMutex);
    return doLowLevelStuff();
}

void highLevelStuff(int someParam)
{
    std::cout << someParam << std::endl;
}

void highLevelFunc()
{
    std::lock_guard<hierarchical_mutex> lk(highLevelMutex);
    highLevelStuff(lowLevelFunc());
}

void threadA()
{
    highLevelFunc();
}

void doOtherStuff()
{
    std::cout << "Other Stuff" << std::endl;
}

void otherStuff()
{
    highLevelFunc();
    doOtherStuff();
}

void threadB()
{
    std::lock_guard<hierarchical_mutex> lk(otherMutex);
    try
    {
        otherStuff(); // 调用的highLevelFunc持有highLevelMutex，已经持有otherMutex就不能对highLevelMutex上锁了
    }
    catch (std::exception e)
    {
        std::cerr << e.what() << std::endl;
    }
}

int main()
{
    std::thread a(threadA);
    a.join();

    std::thread b(threadB);
    b.join();

    return 0;
}
