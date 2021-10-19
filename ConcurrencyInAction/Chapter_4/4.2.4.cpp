#include <cmath>
#include <exception>
#include <future>
#include <iostream>
#include <stdexcept>
#include <thread>

double square_root(double x)
{
    if (x < 0)
    {
        throw std::out_of_range("x < 0");
    }
    return std::sqrt(x);
}

void calculateSquareRoot(std::promise<double>&& somePromise, double x)
{
// #define ANOTHER_WAY
#ifndef ANOTHER_WAY
    try
    {
        somePromise.set_value(square_root(x));
    }
    catch (...)
    {
        somePromise.set_exception(std::current_exception());
    }
#else
    if (x < 0)
    {
        // copy_exception在C++11后被改名为make_exception_ptr
        somePromise.set_exception(std::make_exception_ptr(std::out_of_range("x < 0")));
    }
    else
    {
        somePromise.set_value(square_root(x));
    }
#endif
}

int main()
{
    std::future<double> f = std::async(square_root, -1);
    try
    {
        std::cout << f.get(); // 被调用函数如果抛出异常，异常将被储存在get中，并在调用get时抛出
    }
    catch (std::out_of_range err)
    {
        std::cerr << err.what() << std::endl; // 所以这里能catch到
    }

    std::promise<double> promiseForRes;
    auto res = promiseForRes.get_future();
    auto t1 = std::thread(calculateSquareRoot, std::move(promiseForRes), -1);

    try
    {
        std::cout << res.get();
    }
    catch (std::out_of_range err)
    {
        std::cerr << "using promise: " << err.what() << std::endl;
    }
    t1.join();

    return 0;
}
