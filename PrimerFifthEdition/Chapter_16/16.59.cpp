#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <utility>

template <typename T>
class Vec
{
public:
    Vec();
    Vec(const Vec& orgi);
    Vec(std::initializer_list<T> lst);
    Vec& operator=(const Vec& rhs);
    ~Vec();

    template <typename... Args>
    void emplace_back(Args&&... args)
    {
        chk_n_alloc();
        std::allocator_traits<std::allocator<T>>::construct(alloc, first_free++, std::forward<Args>(args)...);
    }

    void push_back(const T& str);
    void reserve(const size_t& newcapacity);
    void resize(const size_t& newsize);
    size_t size() const;
    size_t capacity() const;
    T* begin() const;
    T* end() const;

private:
    static std::allocator<T> alloc;
    void chk_n_alloc();
    std::pair<T*, T*> alloc_n_copy(const T* begin, const T* end);
    void free();       // 销毁元素并释放内存
    void reallocate(); // 获得更多内存并拷贝已有元素

    T* elements{};   // 指向数组首元素的指针
    T* first_free{}; // 指向数组第一个空闲元素的指针
    T* cap{};        // 指向数组尾后位置的指针
};

template <typename T>
Vec<T>::Vec() = default;

template <typename T>
Vec<T>::Vec(std::initializer_list<T> lst)
{
    for (const auto& str : lst)
    {
        this->push_back(str);
    }
}

template <typename T>
Vec<T>::Vec(const Vec& orgi)
{
    auto newdata = alloc_n_copy(orgi.begin(), orgi.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

template <typename T>
Vec<T>& Vec<T>::operator=(const Vec<T>& rhs)
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

template <typename T>
Vec<T>::~Vec()
{
    free();
}

template <typename T>
void Vec<T>::push_back(const T& str)
{
    chk_n_alloc();
    std::allocator_traits<std::allocator<T>>::construct(alloc, first_free++, str);
}

template <typename T>
void Vec<T>::reserve(const size_t& newcapacity)
{
    if (newcapacity <= capacity())
    {
        return;
    }
    auto* newdata = alloc.allocate(newcapacity);
    auto* dest = newdata;
    auto* elem = elements;
    for (size_t i = 0; i != size(); ++i)
    {
        std::allocator_traits<std::allocator<T>>::construct(alloc, dest++, std::move(*elem++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

template <typename T>
void Vec<T>::resize(const size_t& newsize)
{
    if (newsize > size())
    {
        reserve(newsize);
        for (size_t i = size(); i < newsize; i++)
        {
            std::allocator_traits<std::allocator<T>>::construct(alloc, first_free++, "");
        }
    }
    else if (newsize < size())
    {
        while (first_free != elements + newsize)
        {
            std::allocator_traits<std::allocator<T>>::destroy(alloc, --first_free);
        }
    }
}

template <typename T>
size_t Vec<T>::size() const
{
    return first_free - elements;
}

template <typename T>
size_t Vec<T>::capacity() const
{
    return cap - elements;
}

template <typename T>
T* Vec<T>::begin() const
{
    return elements;
}

template <typename T>
T* Vec<T>::end() const
{
    return first_free;
}

template <typename T>
std::allocator<T> Vec<T>::alloc;

template <typename T>
void Vec<T>::chk_n_alloc()
{
    if (size() == capacity())
    {
        reallocate();
    }
}

template <typename T>
std::pair<T*, T*> Vec<T>::alloc_n_copy(const T* begin, const T* end)
{
    auto* data = alloc.allocate(end - begin);
    return {data, std::uninitialized_copy(begin, end, data)};
}

template <typename T>
void Vec<T>::free()
{
    if (elements)
    {
        for (auto* p = first_free; p != elements;)
        {
            std::allocator_traits<std::allocator<T>>::destroy(alloc, --p);
        }
        alloc.deallocate(elements, cap - elements);
    }
}

template <typename T>
void Vec<T>::reallocate()
{
    auto newcapacity = size() ? 2 * size() : 1;
    auto* newdata = alloc.allocate(newcapacity);
    auto* dest = newdata;
    auto* elem = elements;
    for (size_t i = 0; i != size(); ++i)
    {
        std::allocator_traits<std::allocator<T>>::construct(alloc, dest++, std::move(*elem++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

int main()
{
    Vec<std::string> sv;
    std::string s("Shit");

    sv.emplace_back(s);
    // 用一个拷贝的左值初始化右值的包，包被扩展为右值引用的列表，然后完美转发给construct用来构造新的string

    return 0;
}
