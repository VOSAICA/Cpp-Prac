#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

struct Person
{
private:
    std::string name;
    std::string address;

public:
    Person() = default;
    Person(const std::string&, const std::string&);
    Person(std::istream&);

    std::string get_name() const;    // const成员函数，让const Person对象也能调用它
    std::string get_address() const; // 同上
    void set_name(std::string);
    void set_address(std::string);
};

std::string Person::get_name() const
{
    return name;
}

std::string Person::get_address() const
{
    return address;
}

void Person::set_name(std::string n)
{
    name = n;
}

void Person::set_address(std::string add)
{
    address = add;
}

std::istream& read(std::istream& is, Person& item)
{
    std::string temp;
    std::cout << "Name: \n";
    is >> temp;
    item.set_name(temp);
    std::cout << "Address: \n";
    is >> temp;
    item.set_address(temp);
    return is;
}

std::ostream& print(std::ostream& os, const Person& item)
{
    os << item.get_name() << ' ' << item.get_address() << '\n';
    return os;
}

Person::Person(const std::string& n, const std::string& add) : name(n), address(add)
{
}

Person::Person(std::istream& is)
{
    read(is, *this);
}

#endif
