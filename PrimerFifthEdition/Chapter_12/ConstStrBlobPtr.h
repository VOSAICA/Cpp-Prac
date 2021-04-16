#ifndef CONST_STR_BLOB_H
#define CONST_STR_BLOB_H

#include "StrBlob.h"

class ConstStrBlobPtr
{
public:
    ConstStrBlobPtr();
    ConstStrBlobPtr(const StrBlob& a, size_t sz = 0);

    bool operator!=(ConstStrBlobPtr& p);
    std::string& deref() const;
    ConstStrBlobPtr& incr();

private:
    std::shared_ptr<std::vector<std::string>> check(std::size_t i, const std::string& msg) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};

#endif
