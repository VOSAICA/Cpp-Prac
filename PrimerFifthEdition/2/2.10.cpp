#include <iostream>

std::string global_str;
int global_int;

int main()
{
    int local_int;
    std::cout << "global_str: " << global_str << '\n'
              << "global_int: " << global_int << '\n'
              << "local_int: " << local_int;

    return 0;
}
