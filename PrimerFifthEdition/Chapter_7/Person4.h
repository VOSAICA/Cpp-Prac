#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

struct Person
{
    std::string name;
    std::string address;

    std::string get_name() const;    // const成员函数，让const Person对象也能调用它
    std::string get_address() const; // 同上
};

std::string Person::get_name() const
{
    return name;
}

std::string Person::get_address() const
{
    return address;
}

std::istream& read(std::istream& is, Person& item)
{
    is >> item.name >> item.address;
    return is;
}

std::ostream& print(std::ostream& os, const Person& item)
{
    os << item.get_name() << ' ' << item.get_address() << '\n';
    return os;
}

#endif
