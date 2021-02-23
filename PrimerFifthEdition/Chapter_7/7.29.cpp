#include <iostream>
#include <string>

using std::cout;

class Screen
{
public:
    using pos = std::string::size_type;

    Screen() = default;
    Screen(pos ht, pos wd);
    Screen(pos ht, pos wd, char c);

    char get() const;
    char get(pos r, pos c) const;
    Screen set(char c);
    Screen set(pos r, pos col, char ch);

    Screen move(pos r, pos c);
    void some_member() const;

    Screen display(std::ostream& os);

    const Screen display(std::ostream& os) const;

private:
    pos cursor = 0;
    pos height = 0;
    pos width = 0;
    std::string contents;

    mutable size_t access_ctr; // const对象的mutable成员不是const，所以const成员函数也可以更改它的值

    void do_display(std::ostream& os) const;
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

inline Screen Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline Screen Screen::set(pos r, pos col, char ch)
{
    contents[r * width + col] = ch;
    return *this;
}

inline Screen Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}

inline void Screen::some_member() const
{
    ++access_ctr;
}

Screen Screen::display(std::ostream& os)
{
    do_display(os);
    return *this;
}

const Screen Screen::display(std::ostream& os) const
{
    do_display(os);
    return *this;
}

inline void Screen::do_display(std::ostream& os) const
{
    os << contents;
}

int main()
{
    Screen myScreen(5, 5, 'X');

    // move，set，display不返回引用后，move返回的变为*this的副本，display和set的操作对象都是副本了
    myScreen.move(4, 0).display(cout).set('#');

    cout << '\n';
    myScreen.display(cout);
    cout << '\n';

    return 0;
}
