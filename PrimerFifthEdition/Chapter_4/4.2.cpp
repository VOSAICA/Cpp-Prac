#include <iostream>
#include <vector>

using std::vector;

vector<int> vec{1, 0};
auto a = *vec.begin();
auto b = *(vec.begin());

auto c = *vec.begin() + 1;
auto d = *(vec.begin()) + 1;

int main()
{
    std::cout << a << ' ' << b << ' ' << c << ' ' << d << std::endl;
    std::cout << *(vec.begin() + 1);

    return 0;
}
