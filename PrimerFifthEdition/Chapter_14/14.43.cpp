#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

std::modulus<int> mod;

bool judge_divisible(int num, const std::vector<int>& vi)
{
    return !std::any_of(vi.begin(), vi.end(), [&num](int n) { return mod(num, n) != 0; });
}

int main()
{
    std::cout << judge_divisible(10, {2, 5, 1, 3});

    return 0;
}
