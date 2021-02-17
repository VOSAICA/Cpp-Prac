#include <iostream>

int a = 4, b = 3, c = 2, d = 1;
bool ok = a > b&& b > c&& c > d;
// bool ok = a > b > c > d; 这样会变成用a > b的布尔值和c比，再用这个布尔值和d比

int main()
{
    std::cout << ok;

    return 0;
}
