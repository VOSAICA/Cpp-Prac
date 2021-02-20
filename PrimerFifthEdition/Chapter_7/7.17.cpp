#include <iostream>

using std::cout;

class Fruit1
{
    double radius = 0; // class里访问说明符之前的成员是private的

private:
    double mass = 0;
};

struct Fruit2
{
    double radius = 0; // struct里访问说明符之前的成员的public的

private:
    double mass = 0;
};

int main()
{
    Fruit1 a;
    Fruit2 b;
    cout << a.radius; // 不可访问
    cout << b.radius;

    return 0;
}
// 除此之外struct和class没有区别
