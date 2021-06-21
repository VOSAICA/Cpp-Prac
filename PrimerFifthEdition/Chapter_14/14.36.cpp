#include <iostream>
#include <string>
#include <vector>

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
    std::vector<std::string> vs;
    Read rd;
    std::string content;

    while (content = rd(std::cin), content != "")
    {
        vs.emplace_back(content);
    }

    for (const auto& i : vs)
    {
        std::cout << i;
    }

    return 0;
}
