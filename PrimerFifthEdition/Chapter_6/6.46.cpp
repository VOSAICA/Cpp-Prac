#include <string>

using std::string;

constexpr bool isShorter(const string& s1, const string& s2)
{
    return s1.size() < s2.size(); //不能定义成constexpr因为size()不是constexpr function
}

int main()
{
    string a{ "arst" };
    string b{ "ar" };

    int a[isShorter(a, b)];

    return 0;
}
