#include <atomic>
#include <cassert>
#include <iostream>
#include <thread>

std::atomic<int> x, y;

int main()
{
    std::thread a{[&]()
                  {
                      y.store(20, std::memory_order_relaxed);
                      x.store(10, std::memory_order_relaxed);
                  }};

    std::thread b{[&]()
                  {
                      if (x.load(std::memory_order_relaxed) == 10)
                      {
                          std::cout << "x is 10 now, y is: " << y.load();
                          y.store(10, std::memory_order_relaxed);
                      }
                  }};

    std::thread c{[&]()
                  {
                      if (y.load(std::memory_order_relaxed) == 10)
                      {
                          std::cout << "y is 10 now, x is: " << x.load();
                      }
                  }};

    a.join();
    b.join();
    c.join();

    return 0;
}

/*
-Thread 1-
x.store (1, memory_order_relaxed)
x.store (2, memory_order_relaxed)

-Thread 2-
y = x.load (memory_order_relaxed)
z = x.load (memory_order_relaxed)
assert (y <= z) 没问题

宽松操作对于不同变量可以自由重排
*/
