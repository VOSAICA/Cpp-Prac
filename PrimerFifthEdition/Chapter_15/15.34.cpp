// (a)
// Query q = Query("fiery") & Query("bird") | Query("wind");
//
// Query(const std::string&)
// WordQuery(const std::string& s)
// AndQuery(const Query& left, const Query& right)
// BinaryQuery(left, right, "&")
// Query(std::shared_ptr<Query_base> query)
// Query(std::shared_ptr<Query_base> query)
// OrQuery(const Query& left, const Query& right)
// BinaryQuery(left, right, "|")
// Query(std::shared_ptr<Query_base> query)
// Query(std::shared_ptr<Query_base> query)

// (b)
// cout << q
//
// query.rep()
// Query::rep()
// OrQuery::rep()
// BinaryQuery::rep()
// lhs.rep() rhs.rep()
// AndQuery::rep()
// BinaryQuery::rep()
// lhs.rep() rhs.rep()
// WordQuery::rep()
// WordQuery::rep()
// WordQuery::rep()

// (c)
// q.eval()
//
// Query::eval()
// q->eval()
// OrQuery::eval()
