#include <iostream>
#include <string>

class Book
{
public:
    Book(const std::string& ISBN_ = "", const std::string& Name_ = "", const int& Pages_ = 0, const std::string& Author_ = "")
        : ISBN(ISBN_),
          Name(Name_),
          Pages(Pages_),
          Author(Author_)
    {
    }

    Book(std::istream& in)
    {
        in >> ISBN >> Name >> Pages >> Author;
    }

    operator bool() const
    {
        return ISBN.empty();
    }

private:
    std::string ISBN;
    std::string Name;
    int Pages;
    std::string Author;
};
