#include "13.36.h"
#include <iostream>
#include <set>
#include <string>

void Folder::addMsg(Message* msg)
{
    Msgs.insert(msg);
}

void Folder::remMsg(Message* msg)
{
    Msgs.erase(msg);
}

void Folder::print()
{
    for (auto m : Msgs)
    {
        std::cout << m->contents << '\n';
    }
}

Message::Message(const Message& orgi) : contents(orgi.contents), folders(orgi.folders)
{
    add_to_Folders(orgi);
}

Message::~Message()
{
    remove_from_Folders();
}

void Message::save(Folder& f)
{
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder& f)
{
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message& m)
{
    for (auto f : m.folders)
    {
        f->addMsg(this);
    }
}

void Message::remove_from_Folders()
{
    for (auto f : folders)
    {
        f->remMsg(this);
    }
}

int main()
{
    Folder f;
    Message m1("SMSB?"), m2("WSSB!");
    m1.save(f);
    m2.save(f);
    Message m3 = m2;

    f.print();

    return 0;
}
