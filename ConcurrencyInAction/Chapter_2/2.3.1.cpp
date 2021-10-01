#include <iostream>
#include <stdexcept>
#include <thread>

class scoped_thread
{
    std::thread t;

public:
    explicit scoped_thread(std::thread t_) : t(std::move(t_))
    {
        if (!t.joinable())
        {
            throw std::logic_error("No thread");
        }
    }

    ~scoped_thread()
    {
        t.join();
    }

    scoped_thread(scoped_thread const&) = delete;
    scoped_thread& operator=(scoped_thread const&) = delete;
};

void print()
{
    std::cout << "arst\n";
}

int main()
{
    scoped_thread st((std::thread(print)));

    return 0;
}
