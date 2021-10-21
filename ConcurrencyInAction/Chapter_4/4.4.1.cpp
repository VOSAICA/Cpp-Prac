#include <algorithm>
#include <future>
#include <iostream>
#include <list>

template <typename T>
std::list<T> sequentialQuickSort(std::list<T> input)
{
    if (input.empty())
    {
        return input;
    }

    std::list<T> result;
    result.splice(result.begin(), input, input.begin());
    const T& pivot = *result.begin();
    auto dividePoint = std::partition(input.begin(), input.end(), [&](const T& t) { return t < pivot; });

    std::list<T> lowerPart;
    lowerPart.splice(lowerPart.end(), input, input.begin(), dividePoint);
    auto newLower(sequentialQuickSort(std::move(lowerPart)));
    auto newHigher(sequentialQuickSort(std::move(input)));

    result.splice(result.end(), newHigher);
    result.splice(result.begin(), newLower);
    return result;
}

template <typename T>
std::list<T> parallelQuickSort(std::list<T> input)
{
    if (input.empty())
    {
        return input;
    }

    std::list<T> result;
    result.splice(result.begin(), input, input.begin());
    T const& pivot = *result.begin();
    auto dividePoint = std::partition(input.begin(), input.end(), [&](const T& t) { return t < pivot; });

    std::list<T> lowerPart;
    lowerPart.splice(lowerPart.end(), input, input.begin(), dividePoint);

    std::future<std::list<T>> newLower(std::async(&parallelQuickSort<T>, std::move(lowerPart)));
    auto newHigher(parallelQuickSort(std::move(input)));

    result.splice(result.end(), newHigher);
    result.splice(result.begin(), newLower.get());
    return result;
}

int main()
{
    auto a = std::list<int>();
    for (int i = 300; i > 0; --i)
    {
        a.emplace_back(i);
    }
    auto b = parallelQuickSort(a);

    for (const auto& i : b)
    {
        std::cout << i << '\n';
    }

    return 0;
}
