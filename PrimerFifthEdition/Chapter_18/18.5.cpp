#include <cstdlib>
#include <iostream>
#include <stdexcept>

int main()
{
    try
    {
        throw std::runtime_error("Shit");
    }
    catch (std::exception e)
    {
        std::cerr << e.what() << std::endl;
        std::cerr << "terminating...";
        std::abort();
        throw;
    }

    return 0;
}
