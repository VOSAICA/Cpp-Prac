#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <set>
#include <string>

struct Sales_data;
auto read(std::istream& is, Sales_data& item) -> std::istream&;

struct Sales_data
{
    friend auto read(std::istream& is, Sales_data& item) -> std::istream&;
    friend auto print(std::ostream& os, const Sales_data& item) -> std::ostream&;
    friend class std::hash<Sales_data>;

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

public:
    Sales_data();
    Sales_data(std::string s, unsigned n, double p);
    explicit Sales_data(const std::string& s);
    explicit Sales_data(std::istream& is);

    explicit operator double() const
    {
        return units_sold;
    }

    explicit operator std::string() const
    {
        return bookNo;
    }

    auto isbn() const -> std::string; // 常量成员函数，改变this指针，使其指向常量Sales_data对象
    auto avg_price() const -> double;
    auto combine(const Sales_data& /*rhs*/) -> Sales_data&;
};

Sales_data::Sales_data() : Sales_data("Default", 0, 0)
{
#ifndef NDEBUG
    std::cout << "Default Constructor\n";
#endif
}

Sales_data::Sales_data(std::string s, unsigned n, double p) : bookNo(std::move(s)), units_sold(n), revenue(p * n)
{
#ifndef NDEBUG
    std::cout << "Sales_data(const std::string& s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n)\n";
#endif
}

Sales_data::Sales_data(const std::string& s) : Sales_data(s, 0, 0)
{
#ifndef NDEBUG
    std::cout << "Sales_data(const std::string& s) : Sales_data(s, 0, 0)\n";
#endif
}

Sales_data::Sales_data(std::istream& is)
{
#ifndef NDEBUG
    std::cout << "istream Constructor\n";
#endif
    read(is, *this);
}

auto Sales_data::isbn() const -> std::string
{
    return bookNo;
}

inline auto Sales_data::avg_price() const -> double
{
    if (units_sold != 0U)
    {
        return revenue / units_sold;
    }

    return 0;
}

auto Sales_data::combine(const Sales_data& rhs) -> Sales_data& // 因为常量Sales_data不能combine()，所以不用变成const成员函数
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

auto read(std::istream& is, Sales_data& item) -> std::istream& // IO类不能被拷贝，所以返回引用
{
    double price = 0;
    std::cout << "Book Number: \n";
    is >> item.bookNo;
    std::cout << "How many Sold: \n";
    is >> item.units_sold;
    std::cout << "Price: \n";
    is >> price;
    item.revenue = price * item.units_sold;
    return is;
}

auto print(std::ostream& os, const Sales_data& item) -> std::ostream&
{
    os << "\nInformation from Here: \n";
    os << item.isbn() << ' ' << item.units_sold << ' ' << item.revenue << ' ' << item.avg_price() << '\n';
    return os;
}

auto add(const Sales_data& lhs, const Sales_data& rhs) -> Sales_data
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

#endif

auto operator<(const Sales_data& lhs, const Sales_data& rhs) -> bool
{
    return lhs.isbn() < rhs.isbn();
}

namespace std
{

template <>
struct hash<Sales_data>
{
    using result_type = size_t;
    using argument_type = Sales_data;

    size_t operator()(const Sales_data& s) const;
};

size_t hash<Sales_data>::operator()(const Sales_data& s) const
{
    return hash<std::string>()(s.isbn()) ^ hash<unsigned int>()(s.units_sold) ^ hash<double>()(s.revenue);
}

} // namespace std

auto main() -> int
{
    Sales_data a("AB", 13, 12.98);
    Sales_data b("ABC", 10, 9.98);

    std::set<Sales_data> ss;
    ss.insert(a);
    ss.insert(b);

    return 0;
}
