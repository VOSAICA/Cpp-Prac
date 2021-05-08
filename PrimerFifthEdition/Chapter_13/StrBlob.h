#ifndef STR_BLOB_H
#define STR_BLOB_H

#include <exception>
#include <memory>
#include <string>
#include <vector>

class StrBlob;
class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob
{
    friend StrBlobPtr;
    friend ConstStrBlobPtr;

public:
    using size_type = std::vector<std::string>::size_type;
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
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string& msg) const;
};

class StrBlobPtr
{
public:
    StrBlobPtr();
    StrBlobPtr(StrBlob& a, size_t sz = 0);

    bool operator!=(const StrBlobPtr& p);
    StrBlobPtr operator+(const StrBlob::size_type& p);
    std::string& deref() const;
    StrBlobPtr& incr();

private:
    std::shared_ptr<std::vector<std::string>> check(std::size_t i, const std::string& msg) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};

#include "StrBlob.cpp"

#endif
