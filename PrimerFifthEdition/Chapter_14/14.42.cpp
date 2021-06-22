#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

std::greater<int> greater;
std::not_equal_to<std::string> not_equal_to;
std::multiplies<int> mutiplies;

int main()
{
    std::vector<int> vi{2, 12, 312, 192};
    std::vector<std::string> vs{"pooh", "pooh", "shit", ""};
    std::cout << std::count_if(vi.begin(), vi.end(), [](const int& i) { return greater(i, 42); }) << '\n';
    std::cout << *std::find_if(vs.begin(), vs.end(), [](const std::string& s) -> bool { return not_equal_to(s, "pooh"); })
              << '\n';
    std::transform(vi.begin(), vi.end(), vi.begin(), [](const int& i) { return mutiplies(i, 2); });

    for (const auto& i : vi)
    {
        std::cout << i << ' ';
    }

    return 0;
}
