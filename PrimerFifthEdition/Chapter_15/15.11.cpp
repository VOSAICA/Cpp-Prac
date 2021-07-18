#include <iostream>
#include <string>

class Quote
{
public:
    Quote() = default;

    Quote(const std::string& book, double sales_price) : bookNo(book), price(sales_price)
    {
    }

    std::string isbn() const
    {
        return bookNo;
    }

    virtual double net_price(std::size_t n) const
    {
        return static_cast<double>(n) * price;
    }

    virtual void debug(std::ostream& out) const
    {
        out << "bookNo: " << bookNo << "\nprice: " << price << std::endl;
    }

    virtual ~Quote() = default;

private:
    std::string bookNo;

protected:
    double price = 0.0;
};

class Bulk_quote : public Quote
{
public:
    Bulk_quote() = default;

    Bulk_quote(const std::string& book, double p, std::size_t qty, double disc) : Quote(book, p), min_qty(qty), discount(disc)
    {
    }

    double net_price(std::size_t cnt) const override
    {
        if (cnt >= min_qty)
        {
            return static_cast<double>(cnt) * (1 - discount) * price;
        }
        else
        {
            return static_cast<double>(cnt) * price;
        }
    }

private:
    std::size_t min_qty = 0;
    double discount = 0.0;
};

class Limit_quote : public Quote
{
public:
    Limit_quote() = default;

    Limit_quote(const std::string& book, double p, std::size_t qty, double disc) : Quote(book, p), max_qty(qty), discount(disc)
    {
    }

    double net_price(std::size_t cnt) const override
    {
        if (cnt > max_qty)
        {
            return static_cast<double>(max_qty) * (1 - discount) * price + static_cast<double>(cnt - max_qty) * price;
        }
        else
        {
            return static_cast<double>(cnt) * (1 - discount) * price;
        }
    }

    virtual void debug(std::ostream& out) const override
    {
        Quote::debug(out);
        out << "max_qty: " << max_qty << "\ndiscount: " << discount << std::endl;
    }

private:
    std::size_t max_qty = 0;
    double discount = 0.0;
};

double print_total(std::ostream& os, const Quote& item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
    return ret;
}

int main()
{
    Quote a("A", 2.5);
    Limit_quote b("B", 3.0, 5, 0.2);

    a.debug(std::cout);
    std::cout << '\n';
    b.debug(std::cout);

    return 0;
}
