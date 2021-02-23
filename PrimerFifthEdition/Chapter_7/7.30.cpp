// 显式使用this指针思路更清晰，不过有时会显得多余，如this->访问类内成员
// 可以避免重名问题，像这样：void setAddr(const std::string &addr) { this->addr = addr; }
