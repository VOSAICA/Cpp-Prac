#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

int main()
{
    std::ifstream ifs("8.10_In.txt");
    std::vector<std::string> vec;

    if (ifs)
    {
        std::string str;
        while (std::getline(ifs, str))
        {
            vec.emplace_back(str);
        }
    }

    std::istringstream istrst;
    std::string s;
    for (auto i : vec)
    {
        istrst.clear(); // 下面istrst读完了会fail， 用istrst.str不会刷新
        istrst.str(""); // 可以清空缓冲，要不然多次读写吃内存很多
        // std::cout << istrst.fail();

        istrst.str(i);
        while (istrst >> s)
        {
            std::cout << s << ' ';
        }
    }

    return 0;
}
