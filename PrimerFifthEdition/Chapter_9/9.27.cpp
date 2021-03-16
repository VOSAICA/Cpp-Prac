#include <forward_list>
#include <iostream>

using std::cout;

int main()
{
    std::forward_list<int> flst{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto prev = flst.before_begin();
    auto curr = flst.begin();
    while(curr != flst.end())
    {
        if(*curr %2 == 1)
            curr = flst.erase_after(prev);
        else
        {
            prev = curr;
            ++curr;
        }
    }

    for(const auto i : flst)
        cout << i;

    return 0;
}
