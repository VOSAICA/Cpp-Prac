#include <forward_list>
#include <iostream>
#include <string>

using std::cout;

auto func(std::forward_list<std::string>& flst, const std::string& str1, const std::string& str2) -> void
{
    auto tool = flst.begin();
    auto iter = flst.begin();
    while (*iter != str1 && ++tool != flst.end())
        ++iter;
    flst.insert_after(iter, str2);
}

int main()
{
    std::forward_list<std::string> flst{"0", "1", "2", "3", "4"};
    func(flst, "3", "5");
    func(flst, "9", "10");

    for (const auto i : flst)
        cout << i << ' ';

    return 0;
}
