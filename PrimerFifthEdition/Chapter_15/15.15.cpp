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

class Disc_quote : public Quote
{
public:
    Disc_quote() = default;

    Disc_quote(const std::string& book, double price, std::size_t qty, double disc)
        : Quote(book, price),
          boundaryQuantity(qty),
          discount(disc)
    {
    }

    double net_price(std::size_t qty) const = 0;

protected:
    std::size_t boundaryQuantity = 0;
    double discount = 0.0;
};

class Bulk_quote : public Disc_quote
{
public:
    Bulk_quote() = default;

    Bulk_quote(const std::string& book, double price, std::size_t qty, double disc) : Disc_quote(book, price, qty, disc)
    {
    }

    double net_price(std::size_t qty) const override
    {
        if (qty >= boundaryQuantity)
        {
            return static_cast<double>(qty) * (1 - discount) * price;
        }
        else
        {
            return static_cast<double>(qty) * price;
        }
    }
};
