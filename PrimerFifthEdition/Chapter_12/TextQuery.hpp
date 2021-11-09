#include <algorithm>
#include <fstream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <vector>

class QueryResult;

class TextQuery
{
    friend QueryResult;

public:
    TextQuery(std::ifstream&);

private:
    std::shared_ptr<std::vector<std::string>> file;
    std::shared_ptr<std::map<std::string, std::set<size_t>>> wordAndLine;
};

class QueryResult
{
public:
    QueryResult() = default;
    QueryResult(TextQuery&);
    std::set<size_t> find(const std::string&);

private:
    std::shared_ptr<std::vector<std::string>> file;
    std::shared_ptr<std::map<std::string, std::set<size_t>>> wordAndLine;
};

TextQuery::TextQuery(std::ifstream& ifs) :
    file(new std::vector<std::string>), wordAndLine(new std::map<std::string, std::set<size_t>>)
{
    std::string line;
    size_t lineNo(1);
    while (std::getline(ifs, line))
    {
        TextQuery::file->emplace_back(line);
        std::istringstream iss(line);
        std::string word;

        while (iss >> word)
        {
            (*wordAndLine)[word].insert(lineNo);
        }
        ++lineNo;
    }
}

QueryResult::QueryResult(TextQuery& tq) : file(tq.file), wordAndLine(tq.wordAndLine)
{
}

std::set<size_t> QueryResult::find(const std::string& str)
{
    auto res = wordAndLine->find(str);
    if (res == wordAndLine->end())
    {
        return std::set<size_t>{0};
    }
    else
    {
        return res->second;
    }
}
