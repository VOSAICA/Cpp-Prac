#include <stdexcept>

int main()
{
    try
    {
    }
    catch (std::exception)
    {
    }
    catch (const std::runtime_error& re) // std::runtime_error由std::exception派生，不能被这个catch捕获，会被上一个catch处理
    {
    }
    catch (std::overflow_error eobj) // std::overflow_error由std::runtime_error派生
    {
    }

    try
    {
    }
    catch (std::overflow_error eobj)
    {
    }
    catch (const std::runtime_error& re)
    {
    }
    catch (std::exception)
    {
    }

    return 0;
}
