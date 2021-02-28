#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <vector>

class Screen;

class Window_mgr
{
private:
    std::vector<Screen> screens;

public:
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex);
};

class Screen
{
    friend void Window_mgr::clear(ScreenIndex i);

public:
    using pos = std::string::size_type;

    Screen() = default;
    Screen(pos ht, pos wd);
    Screen(pos ht, pos wd, char c);

    char get() const;
    char get(pos r, pos c) const;
    Screen& set(char c);
    Screen& set(pos r, pos col, char ch);

    Screen& move(pos r, pos c);
    void some_member() const;

    Screen& display(std::ostream& os);
    const Screen& display(std::ostream& os) const;

    pos size() const;

private:
    pos cursor = 0;
    pos height = 0;
    pos width = 0;
    std::string contents;

    mutable size_t access_ctr; // const对象的mutable成员不是const，所以const成员函数也可以更改它的值

    void do_display(std::ostream& os) const;
};

void Window_mgr::clear(ScreenIndex i)
{
    Screen& s = screens[i];
    s.contents = std::string(s.height * s.width, ' ');
}

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

inline Screen& Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline Screen& Screen::set(pos r, pos col, char ch)
{
    contents[r * width + col] = ch;
    return *this;
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

Screen& Screen::display(std::ostream& os)
{
    do_display(os);
    return *this;
}

const Screen& Screen::display(std::ostream& os) const
{
    do_display(os);
    return *this;
}

inline void Screen::do_display(std::ostream& os) const
{
    os << contents;
}

Screen::pos Screen::size() const
{
    return height * width;
}

#endif
