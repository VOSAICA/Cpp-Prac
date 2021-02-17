#ifndef PERSON_H
#define PERSON_H

#include <string>

struct Person
{
    std::string name;
    std::string address;

    std::string get_name() const;
    std::string get_address() const;
};

std::string Person::get_name() const
{
    return name;
}

std::string Person::get_address() const
{
    return address;
}

#endif
