// 函数传递非引用的参数
// Point local = arg, *heap = new Point(global);
// Point pa[4] = {local, *heap};
// return *heap;

#include <iostream>

using std::cout;

class Point
{
public:
    Point() = default;
    Point(const Point& orgi) : a(orgi.a)
    {
        cout << "SB!" << '\n';
    }
    int a;
};

Point global;
Point foo_bar(Point arg)
{
    cout << "20: ";
    Point local = arg, *heap = new Point(global);
    cout << "22: ";
    *heap = local;
    cout << "24: ";
    Point pa[4] = {local, *heap};
    cout << "27: ";

    return *heap;
}

int main()
{
    Point global;
    cout << "32: ";
    auto a = foo_bar(global);

    return 0;
}
