#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>

struct Sales_data
{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    std::string isbn() const; // 常量成员函数，改变this指针，使其指向常量Sales_data对象
    double avg_price() const;
    Sales_data& combine(const Sales_data&);
};

std::string Sales_data::isbn() const
{
    return bookNo;
}

double Sales_data::avg_price() const
{
    if (units_sold)
        return revenue / units_sold;
    else
        return 0;
}

Sales_data& Sales_data::combine(const Sales_data& rhs) // 因为常量Sales_data不能combine()，所以不用变成const成员函数
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

std::istream& read(std::istream& is, Sales_data& item) // IO类不能被拷贝，所以返回引用
{
    double price = 0;
    std::cout << "Book Number: \n"
              << "How many Sold: \n"
              << "Price: \n";
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream& print(std::ostream& os, const Sales_data& item)
{
    os << item.isbn() << '\n' << item.units_sold << '\n' << item.revenue << '\n' << item.avg_price() << '\n';
    return os;
}

Sales_data add(const Sales_data& lhs, const Sales_data& rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

#endif
