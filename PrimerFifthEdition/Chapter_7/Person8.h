#ifndef PERSON_H_8
#define PERSON_H_8

#include <iostream>
#include <string>

class Person
{
    friend std::istream& read(std::istream& is, Person& item);
    friend std::ostream& print(std::ostream& os, const Person& item);

private:
    std::string name;
    std::string address;

public:
    Person() = default;
    Person(const std::string&, const std::string&);
    explicit Person(std::istream&);

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
    std::cout << "Name: \n";
    is >> item.name;
    std::cout << "Address: \n";
    is >> item.address;
    return is;
}

std::ostream& print(std::ostream& os, const Person& item)
{
    os << item.name << ' ' << item.address << '\n';
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
