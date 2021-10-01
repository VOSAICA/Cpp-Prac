#include <iostream>
#include <thread>

void print()
{
    for (auto a = 0; a < 100; ++a)
    {
        std::cout << "    " << a << '\n';
    }
}

int main()
{
    std::thread th(print);
    for (int a = 0; a < 50; ++a)
    {
        std::cout << "Space Holder" << '\n';
    }
    std::thread th2 = std::move(th);
    std::cout << "moved!!!!!!!!!!!!!!!!!!!!\n";

    th2.join();

    return 0;
}
