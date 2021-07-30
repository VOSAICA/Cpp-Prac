// Disc_quote已经有了有4个参数的构造函数，所以不会合成默认构造函数，默认构造函数被隐式删除
// Bulk_quote使用默认构造函数初始化时会调用Disc_quote的默认构造函数
// Bulk_quote继承的时候合成的默认构造函数就找不到Disc_quote的默认构造函数了

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
    // Disc_quote() = default;

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

int main()
{

    return 0;
}
