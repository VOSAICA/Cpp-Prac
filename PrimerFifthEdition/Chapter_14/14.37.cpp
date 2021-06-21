#include <algorithm>
#include <iostream>
#include <vector>


class Equal
{
public:
    Equal(int v) : value(v)
    {
    }
    bool operator()(int a)
    {
        return a == value;
    }

private:
    int value;
};

int main()
{
    std::vector<int> vi{1, 2, 3, 2, 1};
    std::replace_if(vi.begin(), vi.end(), Equal(2), 0);

    for (const auto& i : vi)
    {
        std::cout << i;
    }

    return 0;
}
