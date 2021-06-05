// +---+---+---+---+---+---+---+---+---+---+
// | 0 | 1 | 2 | 3 | 4 |       未构造       |
// +---+---+---+---+---+---+---+---+---+---+
//   ^                   ^                   ^
//   |                   |                   |
//   elements            first_free          cap

#include <iostream>
#include <memory>
#include <string>
#include <utility>

class StrVec
{
public:
    StrVec();
    StrVec(const StrVec& orgi);
    StrVec(std::initializer_list<std::string> lst);
    StrVec& operator=(const StrVec& rhs);
    ~StrVec();

    void push_back(const std::string& str);
    void reserve(const size_t& newcapacity);
    void resize(const size_t& newsize);
    size_t size() const;
    size_t capacity() const;
    std::string* begin() const;
    std::string* end() const;

private:
    static std::allocator<std::string> alloc;
    void chk_n_alloc();
    std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
    void free();             // 销毁元素并释放内存
    void reallocate();       // 获得更多内存并拷贝已有元素
    std::string* elements;   // 指向数组首元素的指针
    std::string* first_free; // 指向数组第一个空闲元素的指针
    std::string* cap;        // 指向数组尾后位置的指针
};

StrVec::StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr)
{
}

StrVec::StrVec(std::initializer_list<std::string> lst) : elements(nullptr), first_free(nullptr), cap(nullptr)
{
    for (const auto& str : lst)
    {
        this->push_back(str);
    }
}

StrVec::StrVec(const StrVec& orgi)
{
    auto newdata = alloc_n_copy(orgi.begin(), orgi.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec& StrVec::operator=(const StrVec& rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

StrVec::~StrVec()
{
    free();
}

void StrVec::push_back(const std::string& str)
{
    chk_n_alloc();
    std::allocator_traits<std::allocator<std::string>>::construct(alloc, first_free++, str);
}

void StrVec::reserve(const size_t& newcapacity)
{
    if (newcapacity <= capacity())
    {
        return;
    }
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
    {
        std::allocator_traits<std::allocator<std::string>>::construct(alloc, dest++, std::move(*elem++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

void StrVec::resize(const size_t& newsize)
{
    if (newsize > size())
    {
        reserve(newsize);
        for (size_t i = size(); i < newsize; i++)
        {
            std::allocator_traits<std::allocator<std::string>>::construct(alloc, first_free++, "");
        }
    }
    else if (newsize < size())
    {
        while (first_free != elements + newsize)
        {
            std::allocator_traits<std::allocator<std::string>>::destroy(alloc, --first_free);
        }
    }
}

size_t StrVec::size() const
{
    return first_free - elements;
}

size_t StrVec::capacity() const
{
    return cap - elements;
}

std::string* StrVec::begin() const
{
    return elements;
}

std::string* StrVec::end() const
{
    return first_free;
}

std::allocator<std::string> StrVec::alloc;

void StrVec::chk_n_alloc()
{
    if (size() == capacity())
    {
        reallocate();
    }
}

std::pair<std::string*, std::string*> StrVec::alloc_n_copy(const std::string* begin, const std::string* end)
{
    auto data = alloc.allocate(end - begin);
    return {data, std::uninitialized_copy(begin, end, data)};
}

void StrVec::free()
{
    if (elements)
    {
        for (auto p = first_free; p != elements;)
        {
            std::allocator_traits<std::allocator<std::string>>::destroy(alloc, --p);
        }
        alloc.deallocate(elements, cap - elements);
    }
}

void StrVec::reallocate()
{
    auto newcapacity = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
    {
        std::allocator_traits<std::allocator<std::string>>::construct(alloc, dest++, std::move(*elem++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

using std::cout;

int main()
{
    StrVec a{"a", "b", "c", "d", "e", "f", "g", "h"};
    a.reserve(13);
    a.resize(3);

    cout << "a.capacity = " << a.capacity() << '\n';
    for (auto& i : a)
    {
        cout << i << ' ';
    }
    cout << '\n';

    a.resize(10);
    for (auto& i : a)
    {
        cout << i << ' ';
    }
    cout << "end";

    return 0;
}
