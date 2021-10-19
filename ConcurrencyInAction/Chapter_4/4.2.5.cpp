#include <cassert>
#include <future>

#undef NDEBUG

int main()
{
    std::promise<int> p;
    std::future<int> f(p.get_future());

    assert(f.valid());
    std::shared_future<int> sf(std::move(f));
    assert(!f.valid());
    assert(sf.valid());

    std::promise<int> p2;
    // std::shared_future<int> sf2(p2.get_future()); // 隐式转移所有权
    auto sf2 = p2.get_future().share();

    return 0;
}
