#include <iostream>

int main()
{
    unsigned scores[11]; //scores未初始化，元素为随机值，程序不好使
    unsigned grade;

    while (std::cin >> grade)
    {
        if (grade <= 100)
            ++scores[grade / 10];
    }

    for (auto a : scores)
        std::cout << a << ' ';
}
