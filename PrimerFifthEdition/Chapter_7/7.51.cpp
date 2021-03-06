#include <iostream>
#include <string>
#include <vector>

using std::cout;

int getSize(const std::vector<int>&);
void setYourName(std::string);

int main()
{
    getSize(34);         //从int直接转换为vector<int>比较困惑
    setYourName("pezy"); //字符串字面值转字符串非常自然

    return 0;
}
