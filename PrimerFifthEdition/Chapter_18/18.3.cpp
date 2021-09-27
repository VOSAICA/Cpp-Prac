// 1.用类分配资源
// 2.用智能指针
#include <fstream>
#include <iostream>
#include <memory>
#include <vector>

void exercise(int* b, int* e)
{
    std::vector<int> v(b, e);
    int* p = new int[v.size()];
    std::ifstream in("ints");
}

void exercise1(int* b, int* e)
{
    std::vector<int> v(b, e);
    std::unique_ptr<int[]> p = std::make_unique<int[]>(v.size());
    std::ifstream in("ints");
}

class array
{
public:
    array() = default;

    array(std::vector<int>::size_type sz) : p(new int[sz])
    {
    }

    ~array()
    {
        delete[] p;
    }

private:
    int* p{};
};

void exercise2(int* b, int* e)
{
    std::vector<int> v(b, e);
    array a = (v.size());
    std::ifstream in("ints");
}
