#include <iostream>

using std::cout;

class Fruit
{
private:
    double mass = 0;
    double radius = 0;

public:
    double get_mass();

public: // 可以使用任意次数的访问说明符
    void set_mass(double);
    double get_raduis();
};

double Fruit::get_mass()
{
    return mass;
}

void Fruit::set_mass(double m)
{
    mass = m;
}

double Fruit::get_raduis()
{
    return radius;
}

int main()
{
    Fruit a;
    a.set_mass(50);
    cout << a.get_mass();

    return 0;
}
