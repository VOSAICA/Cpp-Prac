#include <stdexcept>

int main()
{
    std::range_error r("error");
    throw r; // range_error

    std::exception* p = &r;
    throw *p; // std::exception

    return 0;
}
