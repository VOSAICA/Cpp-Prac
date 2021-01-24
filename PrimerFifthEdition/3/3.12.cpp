#include <string>
#include <vector>

using std::string;
using std::vector;

vector<vector<int>> ivec;
vector<string> svec = ivec; //类型不一致
vector<string> svec(10, "null");
