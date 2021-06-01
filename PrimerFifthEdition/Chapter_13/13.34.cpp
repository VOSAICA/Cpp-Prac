#include <set>
#include <string>

class Folder;

class Message
{
    friend class Folder;

public:
    explicit Message(const std::string& str = "") : contents(str)
    {
    }
    Message(const Message& orgi);
    Message& operator=(const Message& rhs);
    ~Message();

    void save(Folder& f);
    void remove(Folder& f);

private:
    std::string contents;
    std::set<Folder*> folders;
    void add_to_Folders(const Message& m);
    void remove_from_Folders();
};

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
