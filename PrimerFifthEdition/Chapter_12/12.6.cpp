#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::istream;
using std::ostream;
using std::vector;

vector<int>* func()
{
    return new vector<int>();
}

void inputVec(vector<int>* vec, istream& ist)
{
    int temp;
    while (ist >> temp)
        vec->emplace_back(temp);
}

void outputVec(vector<int>* vec, ostream& ost)
{
    for (auto i : *vec)
        ost << i << ' ';
}

int main()
{
    auto a = func();
    inputVec(a, cin);
    outputVec(a, cout);
    delete a;
    a = nullptr;

    return 0;
}
