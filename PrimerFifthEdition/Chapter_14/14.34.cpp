#include <iostream>

class Function
{
public:
    char operator()(bool a, char b, char c)
    {
        return a ? b : c;
    }
};

int main()
{
    Function a;
    std::cout << a(0, 's', 'b');

    return 0;
}
