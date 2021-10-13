#include <iostream>
#include <memory>
#include <mutex>
#include <thread>

struct some_resource
{
    some_resource()
    {
        std::cout << "default initialization\n";
    }

    void do_something()
    {
    }

    int state{};
};

/*
std::shared_ptr<some_resource> resource_ptr;
std::mutex resource_mutex;

void foo()
{
    std::unique_lock<std::mutex> lk(resource_mutex);
    if (!resource_ptr) // 此时已经得到锁
    {
        resource_ptr = std::make_shared<some_resource>();
    }
    lk.unlock();
    resource_ptr->do_something();
}
*/

std::shared_ptr<some_resource> resource_ptr;
std::once_flag resource_flag;

void init_resource()
{
    resource_ptr = std::make_shared<some_resource>();
}

void foo()
{
    std::call_once(resource_flag, init_resource);
    resource_ptr->do_something(); // 此时初始化必定已经被任意线程初始化
}

// 线程安全地初始化全局实例
some_resource& get_some_resource_instance()
{
    static some_resource instance; // 仅初始化时保护数据，用于只读数据
    return instance;
}

int main()
{
    ++get_some_resource_instance().state;
    ++get_some_resource_instance().state;
    std::cout << ++get_some_resource_instance().state;

    return 0;
}
