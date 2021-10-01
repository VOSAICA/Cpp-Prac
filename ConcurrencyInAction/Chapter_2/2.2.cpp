#include <iostream>
#include <string>
#include <thread>
#include <utility>

void func(std::string& str)
{
    std::cout << str;
}

int main()
{
    std::string a("arst");
    std::string b("arst");

    // func(std::move(a)); //不能传递右值到非常量引用
    std::thread my_thread(func, std::ref(b)); // std::thread会拷贝变量，然后右值传递拷贝的参数
    // 用ref把参数变成引用形式

    my_thread.join();

    return 0;
}
