#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

class Book
{
public:
    Book(std::string ISBN_ = "", std::string Name_ = "", int Pages_ = 0, std::string Author_ = "")
        : ISBN(ISBN_), Name(Name_), Pages(Pages_), Author(Author_)
    {
    }

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

#endif
