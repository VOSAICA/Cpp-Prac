#include "TextQuery.hpp"

class Query_base
{
    friend class Query;

protected:
    using line_no = TextQuery::line_no;
    virtual ~Query_base() = default;

private:
    virtual QueryResult eval(const TextQuery&) const = 0;
    virtual std::string rep() const = 0;
};

class Query
{
    friend Query operator~(const Query&);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);

public:
    Query(const std::string&);

    QueryResult eval(const TextQuery& t) const
    {
        return q->eval(t);
    }

    std::string rep() const
    {
        return q->rep();
    }

private:
    Query(const std::shared_ptr<Query_base>& query) : q(query)
    {
        std::cout << "Query(std::shared_ptr<Query_base>)\n";
    }

    std::shared_ptr<Query_base> q;
};

std::ostream& operator<<(std::ostream& os, const Query& query)
{
    return os << query.rep();
}

class WordQuery : public Query_base
{
    friend class Query;

    WordQuery(const std::string& s) : query_word(s)
    {
        std::cout << "WordQuery(const std::string&)\n";
    }

    QueryResult eval(const TextQuery& t) const
    {
        return t.query(query_word);
    }

    std::string rep() const
    {
        return query_word;
    }

    std::string query_word;
};

inline Query::Query(const std::string& s) : q(new WordQuery(s))
{
    std::cout << "Query(const std::string& s)\n";
}

class NotQuery : public Query_base
{
    friend Query operator~(const Query&);

    NotQuery(const Query& q) : query(q)
    {
        std::cout << "NotQuery(const Query& q)\n";
    }

    std::string rep() const
    {
        return "~(" + query.rep() + ");";
    }

    QueryResult eval(const TextQuery&) const
    {
        return QueryResult();
    }

    Query query;
};

inline Query operator~(const Query& operand)
{
    return std::shared_ptr<Query_base>(new NotQuery(operand));
}

class BinaryQuery : public Query_base
{
protected:
    BinaryQuery(const Query& l, const Query& r, const std::string& s) : lhs(l), rhs(r), opSym(s)
    {
        std::cout << "BinaryQuery(const Query&, const Query&, const std::string&)\n";
    }

    std::string rep() const
    {
        return '(' + lhs.rep() + ' ' + opSym + ' ' + rhs.rep() + ')';
    }

    Query lhs, rhs;    // 左侧右侧运算对象
    std::string opSym; // 运算符的名字
};

class AndQuery : public BinaryQuery
{
    friend Query operator&(const Query&, const Query&);

    AndQuery(const Query& left, const Query& right) : BinaryQuery(left, right, "&")
    {
        std::cout << "AndQuery(const Query&, const Query&)\n";
    }

    QueryResult eval(const TextQuery&) const
    {
        return QueryResult();
    }
};

inline Query operator&(const Query& lhs, const Query& rhs)
{
    return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

class OrQuery : public BinaryQuery
{
    friend Query operator|(const Query&, const Query&);

    OrQuery(const Query& left, const Query& right) : BinaryQuery(left, right, "|")
    {
        std::cout << "OrQuery(const Query&, const Query&)\n";
    }

    QueryResult eval(const TextQuery&) const
    {
        return QueryResult();
    }
};

inline Query operator|(const Query& lhs, const Query& rhs)
{
    return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

int main()
{
    Query q = Query("fiery") & Query("bird") | Query("wind");
    std::cout << q;

    return 0;
}
