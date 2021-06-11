#include <iostream>
#include <set>
#include <string>

class Message;

class Folder
{
public:
    void addMsg(Message* msg);
    void remMsg(Message* msg);
    void print();

private:
    std::set<Message*> Msgs;
};

class Message
{
    friend class Folder;

public:
    explicit Message(const std::string& str = "") : contents(str)
    {
    }
    Message(const Message& orgi);
    Message(Message&& msg) noexcept;
    Message& operator=(const Message& rhs);
    Message& operator=(Message&& rhs) noexcept;
    ~Message();

    void save(Folder& f);
    void remove(Folder& f);
    void addFolder(Folder& f);
    void remFolder(Folder& f);
    void move_Folders(Message* msg);

private:
    std::string contents;
    std::set<Folder*> folders;
    void add_to_Folders(const Message& m);
    void remove_from_Folders();
};

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

Message::Message(Message&& msg) noexcept : contents(std::move(msg.contents))
{
    move_Folders(&msg);
}

Message& Message::operator=(Message&& rhs) noexcept
{
    if (this != &rhs)
    {
        remove_from_Folders();
        contents = std::move(rhs.contents);
        move_Folders(&rhs);
    }
    return *this;
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

void Message::addFolder(Folder& f)
{
    folders.insert(&f);
}

void Message::remFolder(Folder& f)
{
    folders.erase(&f);
}

void Message::move_Folders(Message* msg)
{
    folders = std::move(msg->folders);
    for (auto f : folders)
    {
        f->remMsg(msg);
        f->addMsg(this);
    }
    msg->folders.clear();
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
