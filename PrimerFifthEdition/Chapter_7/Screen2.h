#ifndef SCREEN_H
#define SCREEN_H

#include <string>

class Screen
{
public:
    using pos = std::string::size_type;

    Screen() = default;
    Screen(pos ht, pos wd);
    Screen(pos ht, pos wd, char c);

    char get() const;
    char get(pos r, pos c) const;
    Screen& move(pos r, pos c);
    void some_member() const;

private:
    pos cursor = 0;
    pos height = 0;
    pos width = 0;
    std::string contents;

    mutable size_t access_ctr; // const对象的mutable成员不是const，所以const成员函数也可以更改它的值
};

Screen::Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ')
{
}

Screen::Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c)
{
}

inline char Screen::get() const
{
    return contents[cursor];
}

inline char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row + c];
}

inline Screen& Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}

inline void Screen::some_member() const
{
    ++access_ctr;
}

#endif
