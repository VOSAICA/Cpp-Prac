#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

class StrBlob;
class StrBlobPtr;
class ConstStrBlobPtr;

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

class StrBlob
{
    friend StrBlobPtr;
    friend ConstStrBlobPtr;

public:
    using size_type = size_t;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    StrBlob(const StrBlob& orgi);

    StrBlob operator=(const StrBlob& rhs);

    size_type size() const;
    bool empty() const;

    void push_back(const std::string& t);
    void pop_back();

    std::string& front();
    std::string& back();

    StrBlobPtr begin();
    StrBlobPtr end();

private:
    std::shared_ptr<StrVec> data;
    void check(size_type i, const std::string& msg) const;
};

class StrBlobPtr
{
public:
    StrBlobPtr();
    StrBlobPtr(StrBlob& a, size_t sz = 0);

    bool operator!=(const StrBlobPtr& p);
    StrBlobPtr operator+(const StrBlob::size_type& p);
    StrBlobPtr& operator++();
    StrBlobPtr operator++(int);
    StrBlobPtr& operator--();
    StrBlobPtr operator--(int);
    std::string& operator*() const;
    std::string* operator->() const;
    StrBlobPtr& incr();

private:
    std::shared_ptr<StrVec> check(std::size_t i, const std::string& msg) const;
    std::weak_ptr<StrVec> wptr;
    std::size_t curr;
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
    if (&rhs != this)
    {
        auto data = alloc_n_copy(rhs.begin(), rhs.end());
        free();
        elements = data.first;
        first_free = cap = data.second;
    }
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

StrBlob::StrBlob() : data(std::make_shared<StrVec>())
{
}

StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<StrVec>(il))
{
}

StrBlob::StrBlob(const StrBlob& orgi) : data(std::make_shared<StrVec>(*orgi.data))
{
}

StrBlob StrBlob::operator=(const StrBlob& rhs)
{
    data = std::make_shared<StrVec>(*rhs.data);
    return *this;
}

StrBlob::size_type StrBlob::size() const
{
    return data->size();
}

bool StrBlob::empty() const
{
    return (data->size()) == 0;
}

void StrBlob::push_back(const std::string& t)
{
    data->push_back(t);
}

std::string& StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return *data->begin();
}

std::string& StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return *data->end();
}

void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->resize(size() - 1);
}

void StrBlob::check(size_type i, const std::string& msg) const
{
    if (i >= data->size())
        throw std::out_of_range(msg);
}

StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}

StrBlobPtr::StrBlobPtr() : curr(0)
{
}

StrBlobPtr::StrBlobPtr(StrBlob& a, size_t sz) : wptr(a.data), curr(sz)
{
}

std::shared_ptr<StrVec> StrBlobPtr::check(std::size_t i, const ::std::string& msg) const
{
    auto ret = wptr.lock();
    if (ret == nullptr)
        throw std::runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

bool StrBlobPtr::operator!=(const StrBlobPtr& p)
{
    return p.curr != curr;
}

StrBlobPtr StrBlobPtr::operator+(const StrBlob::size_type& p)
{
    StrBlobPtr temp = *this;
    temp.curr += p;
    return temp;
}

StrBlobPtr& StrBlobPtr::operator++()
{
    check(curr, "increment past end of StrBlob");
    ++curr;
    return *this;
}

StrBlobPtr StrBlobPtr::operator++(int)
{
    StrBlobPtr orgi = *this;
    ++*this;
    return orgi;
}

StrBlobPtr& StrBlobPtr::operator--()
{
    --curr;
    check(curr, "decrement past begin of StrBlobPtr");
    return *this;
}

StrBlobPtr StrBlobPtr::operator--(int)
{
    StrBlobPtr orgi = *this;
    --*this;
    return orgi;
}

std::string& StrBlobPtr::operator*() const
{
    auto p = check(curr, "dereference past end");
    return *((*p).begin() + curr);
}

std::string* StrBlobPtr::operator->() const
{
    // 箭头运算符不能丢掉成员访问的含义，只能改变从哪一个对象获取成员
    return &this->operator*(); // 解引用this指针，调用operator*()，取址，返回
}

StrBlobPtr& StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

int main()
{
    StrBlob a{"a", "b", "c", "d", "e", "f", "g", "h"};
    auto b = a.begin();
    std::cout << *b;
    std::cout << *b;
    std::cout << *b;

    return 0;
}
