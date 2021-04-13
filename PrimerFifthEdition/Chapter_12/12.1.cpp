#include <exception>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class StrBlob
{
public:
    using size_type = std::vector<std::string>::size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);

    size_type size() const;
    bool empty() const;

    void push_back(const std::string& t);
    void pop_back();

    std::string& front() const;
    std::string& back() const;

private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string& msg) const;
};

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>())
{
}

StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il))
{
}

StrBlob::size_type StrBlob::size() const
{
    return data->size();
}

bool StrBlob::empty() const
{
    return data->empty();
}

void StrBlob::push_back(const std::string& t)
{
    data->push_back(t);
}

std::string& StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return data->front();
}

std::string& StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

void StrBlob::check(size_type i, const std::string& msg) const
{
    if (i >= data->size())
        throw std::out_of_range(msg);
}

int main()
{
    StrBlob b1;
    {
        StrBlob b2 = {"a", "an", "the"};
        b1 = b2;
        b2.push_back("about");
    }

    std::cout << b1.size();

    return 0;
}
