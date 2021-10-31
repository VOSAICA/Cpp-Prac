#include <atomic>
#include <iostream>

int main()
{
    // load(), store(), exchange()
    // compare_exchange_weak(), compare_exchange_strong()
    int a[]{1, 2, 3, 4, 5};
    std::atomic<int*> p = a;

    auto* q = p.load();
    std::cout << *q << std::endl;

    q = p.fetch_add(3);
    std::cout << *q << std::endl;
    std::cout << *p << std::endl;
    p -= 1;
    std::cout << *p << std::endl;

    return 0;
}
