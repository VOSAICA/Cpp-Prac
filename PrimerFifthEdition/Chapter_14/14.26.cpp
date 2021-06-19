#include <algorithm>
#include <iostream>
#include <memory>
#include <utility>

class String
{
public:
    String();
    String(const char* cp);
    String(const String& orgi);
    String(String&& str) noexcept;
    String& operator=(const String& rhs);
    String& operator=(String&& rhs) noexcept;
    ~String();

    void push_back(const char& str);
    void reserve(const size_t& newcapacity);
    void resize(const size_t& newsize);
    size_t size() const;
    size_t capacity() const;
    char* begin() const;
    char* end() const;
    char& operator[](const size_t& index);
    const char& operator[](const size_t& index) const;

private:
    void chk_n_alloc();
    std::pair<char*, char*> alloc_n_copy(const char*, const char*);
    void free();       // 销毁元素并释放内存
    void reallocate(); // 获得更多内存并拷贝已有元素

    static std::allocator<char> alloc;
    char* elements;   // 指向数组首元素的指针
    char* first_free; // 指向数组第一个空闲元素的指针
    char* cap;        // 指向数组尾后位置的指针
};

String::String() : elements(nullptr), first_free(nullptr), cap(nullptr)
{
    this->reserve(5);
}

String::String(const char* cp) : elements(nullptr), first_free(nullptr), cap(nullptr)
{
    this->reserve(5);
    auto ncp = cp;
    while (*ncp != '\0')
    {
        this->push_back(*ncp++);
    }
}

String::String(const String& orgi)
{
    std::cout << "copy initialization\n";
    auto newdata = alloc_n_copy(orgi.begin(), orgi.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

String::String(String&& str) noexcept : elements(str.elements), first_free(str.first_free), cap(str.cap)
{
    std::cout << "move constructor\n";
    str.elements = str.first_free = str.cap = nullptr;
}

String& String::operator=(const String& rhs)
{
    if (this != &rhs)
    {
        auto data = alloc_n_copy(rhs.begin(), rhs.end());
        free();
        elements = data.first;
        first_free = cap = data.second;
    }
    return *this;
}

String& String::operator=(String&& rhs) noexcept
{
#ifndef NDEBUG
    std::clog << "move assignment\n";
#endif
    if (this != &rhs)
    {
        this->elements = rhs.elements;
        this->first_free = rhs.first_free;
        this->cap = rhs.cap;

        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
};

String::~String()
{
    free();
}

void String::push_back(const char& str)
{
    chk_n_alloc();
    std::allocator_traits<std::allocator<char>>::construct(alloc, first_free++, str);
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
        std::allocator_traits<std::allocator<char>>::construct(alloc, dest++, *elem++);
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
            std::allocator_traits<std::allocator<char>>::construct(alloc, first_free++);
        }
    }
    else if (newsize < size())
    {
        while (first_free != elements + newsize)
        {
            std::allocator_traits<std::allocator<char>>::destroy(alloc, --first_free);
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

char* String::begin() const
{
    return elements;
}

char* String::end() const
{
    return first_free;
}

char& String::operator[](const size_t& index)
{
    return *(begin() + index);
}
const char& String::operator[](const size_t& index) const
{
    return *(begin() + index);
}

void String::chk_n_alloc()
{
    if (size() == capacity())
    {
        reallocate();
    }
}

std::pair<char*, char*> String::alloc_n_copy(const char* begin, const char* end)
{
    auto data = alloc.allocate(end - begin);
    return {data, std::uninitialized_copy(begin, end, data)};
}

void String::free()
{
    if (elements)
    {
        std::for_each(elements, first_free, [](char& s) { std::allocator_traits<std::allocator<char>>::destroy(alloc, &s); });
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
        std::allocator_traits<std::allocator<char>>::construct(alloc, dest++, *elem++);
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

std::allocator<char> String::alloc;

std::ostream& operator<<(std::ostream& os, const String& str)
{
    for (auto c : str)
    {
        os << c;
    }
    return os;
}

bool operator==(const String& lhs, const String& rhs)
{
    for (auto lIter = lhs.begin(), rIter = rhs.begin(); lIter != lhs.end() && rIter != rhs.end(); ++lIter, ++rIter)
    {
        if (*lIter != *rIter)
        {
            return false;
        }
    }
    return true;
}

bool operator!=(const String& lhs, const String& rhs)
{
    return !(lhs == rhs);
}

using std::cout;

int main()
{
    String a("you");

    cout << a[0] << a[1] << a[2] << a[3];

    return 0;
}
