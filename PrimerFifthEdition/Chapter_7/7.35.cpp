#include <string>

using std::string;

using Type = string;

Type initVal();

class Exercise
{
public:
    using Type = double;
    Type setVal(Type);
    Type initVal()
    {
        return 0;
    }

private:
    int val;
};

Exercise::Type Exercise::setVal(Type parm)
{
    val = parm + initVal(); // double相加
    return val;             //返回double
}

int main()
{
    return 0;
}
