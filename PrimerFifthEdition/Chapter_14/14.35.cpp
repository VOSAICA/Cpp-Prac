#include <iostream>
#include <string>

class Read
{
public:
    std::string operator()(std::istream& is = std::cin)
    {
        std::string t;
        is >> t;
        return t;
    }
};

int main()
{
    Read rd;
    std::cout << rd(std::cin);

    return 0;
}
