#include "ConstStrBlobPtr.h"

ConstStrBlobPtr::ConstStrBlobPtr() : curr(0)
{
}

ConstStrBlobPtr::ConstStrBlobPtr(const StrBlob& a, size_t sz) : wptr(a.data), curr(sz)
{
}

std::shared_ptr<std::vector<std::string>> ConstStrBlobPtr::check(std::size_t i, const ::std::string& msg) const
{
    auto ret = wptr.lock();
    if (ret == nullptr)
        throw std::runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

bool ConstStrBlobPtr::operator!=(ConstStrBlobPtr& p)
{
    return p.curr != curr;
}

std::string& ConstStrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

ConstStrBlobPtr& ConstStrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}
