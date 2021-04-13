#include <iostream>
#include <memory>
#include <vector>

using std::cin;
using std::cout;
using std::istream;
using std::make_shared;
using std::ostream;
using std::shared_ptr;
using std::vector;

shared_ptr<vector<int>> func()
{
    return make_shared<vector<int>>();
}

void inputVec(shared_ptr<vector<int>> vec, istream& ist)
{
    int temp;
    while (ist >> temp)
        vec->emplace_back(temp);
}

void outputVec(shared_ptr<vector<int>> vec, ostream& ost)
{
    for (auto i : *vec)
        ost << i << ' ';
}

int main()
{

    auto a = func();
    inputVec(a, cin);
    cin.clear();

    auto b = func();
    inputVec(b, cin);
    outputVec(b, cout);

    a = b;

    return 0;
}
