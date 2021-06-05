#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <utility>

class String
{
public:
    String();
    String(const String& orgi);
    String(std::initializer_list<std::string> lst);
    String& operator=(const String& rhs);
    ~String();

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

String::String() : elements(nullptr), first_free(nullptr), cap(nullptr)
{
}

String::String(std::initializer_list<std::string> lst) : elements(nullptr), first_free(nullptr), cap(nullptr)
{
    for (const auto& str : lst)
    {
        this->push_back(str);
    }
}

String::String(const String& orgi)
{
    auto newdata = alloc_n_copy(orgi.begin(), orgi.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

String& String::operator=(const String& rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

String::~String()
{
    free();
}

void String::push_back(const std::string& str)
{
    chk_n_alloc();
    std::allocator_traits<std::allocator<std::string>>::construct(alloc, first_free++, str);
}

void String::reserve(const size_t& newcapacity)
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

void String::resize(const size_t& newsize)
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

size_t String::size() const
{
    return first_free - elements;
}

size_t String::capacity() const
{
    return cap - elements;
}

std::string* String::begin() const
{
    return elements;
}

std::string* String::end() const
{
    return first_free;
}

std::allocator<std::string> String::alloc;

void String::chk_n_alloc()
{
    if (size() == capacity())
    {
        reallocate();
    }
}

std::pair<std::string*, std::string*> String::alloc_n_copy(const std::string* begin, const std::string* end)
{
    auto data = alloc.allocate(end - begin);
    return {data, std::uninitialized_copy(begin, end, data)};
}

void String::free()
{
    if (elements)
    {
        std::for_each(elements, first_free, [](std::string& s) {
            std::allocator_traits<std::allocator<std::string>>::destroy(alloc, &s);
        });
        alloc.deallocate(elements, cap - elements);
    }
}

void String::reallocate()
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
    String a{"a", "b", "c", "d", "e", "f", "g", "h"};
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
