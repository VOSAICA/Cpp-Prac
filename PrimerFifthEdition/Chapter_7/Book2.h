#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

class Book
{
public:
    Book();
    Book(std::string isbn, std::string name, int pages, std::string author);
    Book(std::istream& in)
    {
        in >> ISBN >> Name >> Pages >> Author;
    }

private:
    std::string ISBN;
    std::string Name;
    int Pages;
    std::string Author;
};

Book::Book() : Book("", "", 0, "")
{
}

Book::Book(std::string isbn, std::string name, int pages, std::string author)
    : ISBN(isbn), Name(name), Pages(pages), Author(author)
{
}

#endif
