#include <iostream>
#include <string>

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

    Bulk_quote(const std::string& book, double price, std::size_t qty, double disc) : Disc_quote(book, price, qty, disc)
    {
    }

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
    Quote a;
    std::cout << "\n";

    Bulk_quote b;
    std::cout << "\n";

    Bulk_quote c = b;
    std::cout << "\n";

    Bulk_quote d("foo", 13, 5, 0.1);
    d = d;
    std::cout << "\n";

    return 0;
}
