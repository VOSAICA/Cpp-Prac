#ifndef _13_36_H
#define _13_36_H

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

#endif
