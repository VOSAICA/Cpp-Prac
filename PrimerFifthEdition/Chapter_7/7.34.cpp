#include <string>

int height;
class Screen
{
    // using pos = std::string::size_type;

public:
    void dubby_fcn(pos height)
    {
        cursor = width * height;
    }

private:
    pos cursor = 0;
    pos height = 0, width = 0;

    using pos = std::string::size_type; // 声明中使用的名字，包括返回类型或者参数列表中使用的名字，都必须在生命前确保可见
};
