#include <algorithm>
#include <list>
#include <mutex>
#include <string>

class some_data
{
    int a;
    std::string b;

public:
    void do_something();
};

class data_wrapper
{
private:
    some_data data;
    std::mutex m;

public:
    template <typename Function>
    void process_data(Function func)
    {
        std::lock_guard<std::mutex> l(m);
        func(data);
    }

    some_data* unprotected;
};

some_data* a;
void malicious_function(some_data& protected_data)
{
    some_data* unprotected = &protected_data;
    a = unprotected; // get a pointer to unprotected data
}

data_wrapper x;

void foo()
{
    x.process_data(malicious_function);
}

int main()
{
    foo();

    return 0;
}
