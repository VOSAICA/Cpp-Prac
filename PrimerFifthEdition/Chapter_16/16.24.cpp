#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

template <typename T>
class BlobPtr;

template <typename T>
class Blob;

template <typename T>
bool operator==(const Blob<T>& lhs, const Blob<T>& rhs);

template <typename T>
bool operator<(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);

template <typename T>
class Blob
{
    friend class BlobPtr<T>;
    friend bool operator==<T>(const Blob<T>& lhs, const Blob<T>& rhs);

public:
    using value_type = T;
    using size_type = typename std::vector<T>::size_type;

    Blob<T>() : data(std::make_shared<std::vector<T>>())
    {
    }

    Blob<T>(std::initializer_list<T> il) : data(std::make_shared<std::vector<T>>(il))
    {
    }

    template <typename SB>
    Blob<T>(SB begin, SB end) : data(std::make_shared<std::vector<T>>(begin, end))
    {
    }

    Blob<T>(const Blob<T>& orgi) : data(std::make_shared<std::vector<T>>(*orgi.data))
    {
    }

    Blob<T>& operator=(const Blob& rhs)
    {
        data = std::make_shared<std::vector<T>>(*rhs.data);
        return *this;
    }

    size_type size() const
    {
        return data->size();
    };

    bool empty() const
    {
        return data->empty();
    };

    void push_back(const T& t)
    {
        data->push_back(t);
    }

    void push_back(T&& t)
    {
        data->push_back(std::move(t));
    }

    void pop_back()
    {
        check(0, "pop_back on empty Blob");
        data->pop_back();
    }

    T& front() const
    {
        check(0, "front on empty Blob");
        return data->front();
    }

    T& back() const
    {
        check(0, "back on empty Blob");
        return data->back();
    }

    BlobPtr<T> begin()
    {
        return BlobPtr<T>(*this);
    }

    BlobPtr<T> end()
    {
        return BlobPtr<T>(*this, size());
    }

    T& operator[](size_type i) const
    {
        check(i, "subscript out of range");
        return (*data)[i];
    }

private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type i, const std::string& msg) const
    {
        if (i >= data->size())
        {
            throw std::out_of_range(msg);
        }
    }
};

template <typename T>
class BlobPtr
{
    // clang-format off
    friend bool operator< <T>(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);
    // clang-format on

public:
    BlobPtr<T>() = default;

    BlobPtr<T>(Blob<T>& a, size_t sz = 0) : wptr(a.data), curr(sz)
    {
    }

    bool operator!=(const BlobPtr& rhs) const
    {
        return rhs.curr != curr;
    }

    BlobPtr<T> operator+(const BlobPtr& rhs) const
    {
    }

    T& operator*() const
    {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }

    BlobPtr<T>& operator++()
    {
        check(curr, "increment past end of BlobPtr");
        ++curr;
        return *this;
    }

    BlobPtr<T>& operator--()
    {
        --curr;
        check(curr, "increment past end of BlobPtr");
        return *this;
    }

    BlobPtr<T> operator++(int)
    {
        BlobPtr<T> ret = *this;
        ++*this;
        return ret;
    }

    BlobPtr<T> operator--(int)
    {
        BlobPtr<T> ret = *this;
        --*this;
        return ret;
    }

private:
    std::shared_ptr<std::vector<T>> check(std::size_t i, const std::string& msg) const
    {
        auto ret = wptr.lock();
        if (ret == nullptr)
        {
            throw std::runtime_error("unbound StrBlobPtr");
        }
        if (i >= ret->size())
        {
            throw std::out_of_range(msg);
        }
        return ret;
    }

    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr{};
};

template <typename T>
bool operator==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
{
    if (lhs.wptr.lock() != rhs.wptr.lock())
    {
        throw std::runtime_error("BlobPtr to different Blob");
    }
    return lhs.curr == rhs.curr;
}

template <typename T>
bool operator<(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs)
{
    if (lhs.wptr.lock() != rhs.wptr.lock())
    {
        throw std::runtime_error("BlobPtr to different Blob");
    }
    return lhs.curr < rhs.curr;
}

int main()
{
    std::vector<int> vi{0, 1, 2, 3, 4};
    std::vector<int> v(vi.begin(), vi.end());

    Blob<int> a(vi.begin(), vi.end());

    for (const auto& i : a)
    {
        std::cout << i << ' ';
    }

    return 0;
}
