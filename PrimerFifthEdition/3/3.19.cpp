#include <vector>

using std::vector;

int main()
{
    vector<int> a(10, 42);
    vector<int> b{42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
    vector<int> c;
    for (int i = 0; i < 10; i++)
        c.emplace_back(42);

    return 0;
}
