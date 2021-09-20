#include <iostream>
#include <thread>

void hello()
{
    int a;
    std::cin >> a;
    std::cout << "Hello Concurrent World\n";
}

int main()
{
    std::thread t(hello);
    t.join();

    return 0;
}
