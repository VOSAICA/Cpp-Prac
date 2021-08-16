#include <iostream>
#include <memory>
#include <set>
#include <string>
#include <utility>
#include <vector>

class Quote
{
public:
    Quote()
    {
        bookNo = "";
        price = 0;
    }

    Quote(const std::string& book, double sales_price) : bookNo(book), price(sales_price)
    {
    }

    Quote(const Quote& orgi)
    {
        bookNo = orgi.bookNo;
        price = orgi.price;
    }

    Quote(Quote&& orgi) noexcept
    {
        bookNo = std::move(orgi.bookNo);
        price = orgi.price;
    }

    Quote& operator=(const Quote& rhs)
    {
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

    virtual Quote* clone() const&
    {
        return new Quote(*this);
    }

    virtual Quote* clone() &&
    {
        return new Quote(std::move(*this));
    }

    virtual ~Quote()
    {
    }

private:
    std::string bookNo;

protected:
    double price;
};

double print_total(std::ostream& os, const Quote& item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
    return ret;
}

class Disc_quote : public Quote
{
public:
    Disc_quote() : Quote()
    {
        boundaryQuantity = 0;
        discount = 0;
    }

    Disc_quote(const Disc_quote& orgi) : Quote(orgi)
    {
        boundaryQuantity = orgi.boundaryQuantity;
        discount = orgi.discount;
    }

    Disc_quote(Disc_quote&& orgi) noexcept : Quote(std::move(orgi))
    {
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
    }

    Bulk_quote(const Bulk_quote& orgi) : Disc_quote(orgi)
    {
    }

    Bulk_quote(Bulk_quote&& orgi) noexcept : Disc_quote(std::move(orgi))
    {
    }

    using Disc_quote::Disc_quote;
    /* 只有这个被继承了，默认 拷贝 移动构造函数不会被继承
    Bulk_quote(const std::string& book, double price, std::size_t qty, double disc) : Disc_quote(book, price, qty, disc)
    {
    }
    */

    Bulk_quote& operator=(const Bulk_quote& rhs)
    {
        Disc_quote::operator=(rhs);

        return *this;
    }

    virtual Bulk_quote* clone() const& override
    {
        return new Bulk_quote(*this);
    }

    virtual Bulk_quote* clone() && override
    {
        return new Bulk_quote(std::move(*this));
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

class Basket
{
public:
    void add_item(const std::shared_ptr<Quote>& sale)
    {
        items.insert(sale);
    }

    void add_item(const Quote& sale)
    {
        items.insert(std::shared_ptr<Quote>(sale.clone()));
    }

    void add_item(Quote&& sale)
    {
        items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
    }

    double total_receipt(std::ostream& os) const
    {
        double sum = 0.0;
        for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter))
        {
            sum += print_total(os, **iter, items.count(*iter));
        }
        os << "Total Sale: " << sum << std::endl;
        return sum;
    }

private:
    static bool compare(const std::shared_ptr<Quote>& lhs, const std::shared_ptr<Quote>& rhs)
    {
        return lhs->isbn() < rhs->isbn();
    }

    std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{compare};
};

int main()
{
    Basket bas;

    Quote q("0-091-63141-3", 64);
    bas.add_item(std::move(q));

    bas.add_item(Quote("0-201-82470-1", 50));
    bas.add_item(Quote("0-201-82470-1", 50));

    bas.add_item(Bulk_quote("0-890-12683-9", 64, 10, 0.2));

    bas.total_receipt(std::cout);

    return 0;
}
