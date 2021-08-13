#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

class Quote
{
public:
    Quote()
    {
        std::cout << "Quote()\n";
        bookNo = "";
        price = 0;
    }

    Quote(const Quote& orgi)
    {
        std::cout << "Quote(const Quote&)\n";
        bookNo = orgi.bookNo;
        price = orgi.price;
    }

    Quote(const std::string& book, double sales_price) : bookNo(book), price(sales_price)
    {
    }

    Quote& operator=(const Quote& rhs)
    {
        std::cout << "Quote& operator=(const Quote&)\n";
        if (this != &rhs)
        {
            this->bookNo = rhs.bookNo;
            this->price = rhs.price;
        }

        return *this;
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

    virtual ~Quote()
    {
        std::cout << "~Quote()\n";
    }

private:
    std::string bookNo;

protected:
    double price;
};

class Disc_quote : public Quote
{
public:
    Disc_quote() : Quote()
    {
        std::cout << "Disc_quote()\n";
        boundaryQuantity = 0;
        discount = 0;
    }

    Disc_quote(const Disc_quote& orgi) : Quote(orgi)
    {
        std::cout << "Disc_quote(const Disc_quote&)\n";
        boundaryQuantity = orgi.boundaryQuantity;
        discount = orgi.discount;
    }

    Disc_quote(const std::string& book, double price, std::size_t qty, double disc)
        : Quote(book, price),
          boundaryQuantity(qty),
          discount(disc)
    {
    }

    Disc_quote& operator=(const Disc_quote& rhs)
    {
        std::cout << "Disc_quote& operator=(const Disc_quote& rhs)\n";
        Quote::operator=(rhs);
        if (this != &rhs)
        {
            this->boundaryQuantity = rhs.boundaryQuantity;
            this->discount = rhs.discount;
        }

        return *this;
    }

    virtual double net_price(std::size_t qty) const = 0;

protected:
    std::size_t boundaryQuantity;
    double discount;
};

class Bulk_quote : public Disc_quote
{
public:
    Bulk_quote() : Disc_quote()
    {
        std::cout << "Bulk_quote()\n";
    }

    Bulk_quote(const Bulk_quote& orgi) : Disc_quote(orgi)
    {
        std::cout << "Bulk_quote(const Bulk_quote&)\n";
    }

    using Disc_quote::Disc_quote;
    /* 只有这个被继承了，默认 拷贝 移动构造函数不会被继承
    Bulk_quote(const std::string& book, double price, std::size_t qty, double disc) : Disc_quote(book, price, qty, disc)
    {
    }
    */

    Bulk_quote& operator=(const Bulk_quote& rhs)
    {
        std::cout << "Bulk_quote& operator=(const Bulk_quote&)\n";
        Disc_quote::operator=(rhs);

        return *this;
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
    using namespace std;

    vector<shared_ptr<Quote>> basket;
    basket.push_back(make_shared<Quote>("0-201-82470-1", 50));
    basket.push_back(make_shared<Bulk_quote>("0-890-12683-9", 64, 10, 0.2));

    cout << basket.back()->net_price(20) << endl;

    return 0;
}

// 结果不同，有动态绑定
