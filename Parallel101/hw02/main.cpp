#include <cstdio>
#include <memory>

struct Node
{
    std::unique_ptr<Node> next{nullptr};
    Node* prev{nullptr};

    int value;

    Node(int val) : value{val}
    {
    }

    void insert(int val)
    {
        auto newNode{std::make_unique<Node>(val)};
        newNode->prev = this;

        if (next != nullptr)
        {
            next->prev = newNode.get();
            newNode->next = std::move(next);
        }

        next = std::move(newNode);
    }

    void erase()
    {
        if (prev != nullptr)
        {
            prev->next = std::move(next);
        }
        if (next != nullptr)
        {
            next->prev = prev;
        }
    }

    ~Node()
    {
        printf("~Node(%i)\n", value);
    }
};

struct List
{
    std::unique_ptr<Node> head{nullptr};

    List() = default;

    List(List const& other)
    {
        printf("List 被拷贝!\n");
        head = std::make_unique<Node>(other.head->value);
        auto* cur{head.get()};
        auto* otherCur{other.head.get()};
        while (otherCur->next != nullptr)
        {
            cur->next = std::make_unique<Node>(otherCur->next->value);
            cur->next->prev = cur;
            cur = cur->next.get();
            otherCur = otherCur->next.get();
        }
    }

    List& operator=(List const&) = delete; // 为什么删除拷贝赋值函数也不出错？

    List(List&&) = default;
    List& operator=(List&&) = default;

    [[nodiscard]] Node* front() const
    {
        return head.get();
    }

    int pop_front()
    {
        int ret = head->value;
        head = std::move(head->next);
        return ret;
    }

    void push_front(int value)
    {
        auto newNode = std::make_unique<Node>(value);
        if (head != nullptr)
        {
            head->prev = newNode.get();
            newNode->next = std::move(head);
        }

        head = std::move(newNode);
    }

    [[nodiscard]] Node* operator[](size_t index) const
    {
        auto* curr = front();
        for (size_t i{0}; i < index; ++i)
        {
            curr = curr->next.get();
        }
        return curr;
    }
};

void print(const List& lst)
{
    printf("[");
    for (auto* curr = lst.front(); curr != nullptr; curr = curr->next.get())
    {
        printf(" %d", curr->value);
    }
    printf(" ]\n");
}

int main()
{
    List a{};

    a.push_front(7);
    a.push_front(5);
    a.push_front(8);
    a.push_front(2);
    a.push_front(9);
    a.push_front(4);
    a.push_front(1);

    print(a); // [ 1 4 9 2 8 5 7 ]

    a[2]->erase();

    print(a); // [ 1 4 2 8 5 7 ]

    List b = a;

    a[3]->erase();

    print(a); // [ 1 4 2 5 7 ]
    print(b); // [ 1 4 2 8 5 7 ]

    b = {};
    a = {};

    return 0;
}
