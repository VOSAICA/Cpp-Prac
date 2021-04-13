#include <memory>

using std::make_shared;
using std::shared_ptr;

int main()
{
    int* q = new int(42);
    int* r = new int(100);
    r = q; // r无法被释放

    auto q2 = make_shared<int>(42);
    auto r2 = make_shared<int>(100);
    r2 = q2; // r2已经被释放

    return 0;
}
