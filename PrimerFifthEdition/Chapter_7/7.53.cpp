#include <iostream>

using std::cout;

class Debug
{
public:
    constexpr Debug(bool b = true) : hw(b), io(b), other(b)
    {
    }
    constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o)
    {
    }
    constexpr bool any()
    {
        return hw || io || other;
    }
    void set_hw(bool b)
    {
        hw = b;
    }
    void set_other(bool b)
    {
        hw = b;
    }

private:
    bool hw;
    bool io;
    bool other;
};

int main()
{
    constexpr Debug a = {false};
    cout << a.any();

    return 0;
}
