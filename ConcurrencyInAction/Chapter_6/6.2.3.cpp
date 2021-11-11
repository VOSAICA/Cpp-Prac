#include <iostream>
#include <memory>
#include <mutex>
#include <string>
#include <thread>

//////////////////////////////////////////////////// the most ordinary queue ///////////////////////////////////////////////////
template <typename T>
class queue
{
private:
    struct node
    {
        T data{};
        std::unique_ptr<node> next{};

        node(T data_) : data{std::move(data_)}
        {
        }
    };

    std::unique_ptr<node> head{};
    node* tail{};

public:
    queue() = default;
    queue(const queue&) = delete;
    queue& operator=(const queue&) = delete;

    std::shared_ptr<T> try_pop()
    {
        if (!head)
        {
            return std::shared_ptr<T>{};
        }
        std::shared_ptr<T> res{std::make_shared<T>(std::move(head->data))};
        // head = std::move(head->next);
        const std::unique_ptr<node> old_head = std::move(head);
        head = std::move(old_head->next);
        // 这里有bug，在queue只有一个元素时tail没被置空
        return res;
    }

    void push(T new_value)
    {
        std::unique_ptr<node> new_node{std::make_unique<node>(std::move(new_value))};
        // head和tail可能是同一个对象，多线程时怎么上锁？
        node* const new_tail = new_node.get();
        if (tail)
        {
            tail->next = std::move(new_node);
        }
        else // 因为这时head还是nullptr，所以不能只从tail指向new_node
        {
            head = std::move(new_node);
        }

        tail = new_tail;
    }
};

///////////////////////////////////////////////// the queue uses a virtual node ////////////////////////////////////////////////
template <typename T>
class queue_virtual
{
private:
    struct node
    {
        std::shared_ptr<T> data{nullptr};
        std::unique_ptr<node> next{nullptr};
    };

    // head和tail只持有数据的指针
    std::unique_ptr<node> head;
    node* tail;

public:
    queue_virtual() : head{std::make_unique<node>()}, tail{head.get()}
    {
    }
    queue_virtual(const queue_virtual&) = delete;
    queue_virtual& operator=(const queue_virtual&) = delete;

    std::shared_ptr<T> try_pop()
    {
        if (head.get() == tail)
        {
            return std::shared_ptr<T>{nullptr};
        }
        // 这里已经可以释放tail的锁，已知head和tail是两个节点
        std::shared_ptr<T> data{head->data};
        // head = std::move(head->next);
        std::unique_ptr<node> old_head = std::move(head);
        head = std::move(old_head->next);
        return data;
    }

    void push(T new_value)
    {
        // 现在的push()只用访问tail
        std::shared_ptr<T> new_data{std::make_shared<T>(std::move(new_value))};
        tail->data = new_data;
        std::unique_ptr<node> new_node{std::make_unique<node>()};
        node* const new_tail = new_node.get();
        tail->next = std::move(new_node);
        tail = new_tail;
    }
};

/////////////////////////////////////////////////// the queue is thread safe ///////////////////////////////////////////////////
template <typename T>
class threadsafe_queue
{
private:
    struct node
    {
        std::shared_ptr<T> data;
        std::unique_ptr<node> next;
    };

    std::unique_ptr<node> head;
    node* tail;
    std::mutex head_mutex;
    std::mutex tail_mutex;

    node* get_tail()
    {
        std::lock_guard<std::mutex> tail_lock(tail_mutex);
        return tail;
    }

    std::unique_ptr<node> pop_head()
    {
        std::lock_guard<std::mutex> head_lock(head_mutex);
        if (head.get() == get_tail())
        {
            return std::unique_ptr<node>{nullptr};
        }
        std::unique_ptr<node> old_head = std::move(head);
        head = std::move(old_head->next);
        return old_head;
    }

public:
    threadsafe_queue() : head{std::make_unique<node>()}, tail{head.get()}
    {
    }

    threadsafe_queue(const threadsafe_queue& orgi) = delete;
    threadsafe_queue& operator=(const threadsafe_queue& orgi) = delete;

    std::shared_ptr<T> try_pop()
    {
        const std::unique_ptr<node> old_head = pop_head();
        return old_head ? old_head->data : std::shared_ptr<T>{nullptr};
    }

    void push(T new_value)
    {
        std::shared_ptr<T> new_data{std::make_shared<T>(std::move(new_value))};
        std::unique_ptr<node> new_node{std::make_unique<node>()};
        node* const new_tail = new_node.get();
        std::lock_guard<std::mutex> tail_lock(tail_mutex);
        tail->data = new_data;
        tail->next = std::move(new_node);
        tail = new_tail;
    }
};

int main()
{
    // queue<int> a{};
    // a.push(1);
    // std::cout << *a.try_pop();
    // a.push(2);
    // // std::cout << *a.try_pop(); // 书上的实现有bug

    queue_virtual<int> b{};
    b.push(1);
    std::cout << *b.try_pop();
    b.push(2);
    std::cout << *b.try_pop();

    threadsafe_queue<std::string> c{};

    std::thread t1{[&]() { c.push("a"); }};
    std::thread t2{[&]() { c.try_pop(); }};
    std::thread t3{[&]() { c.push("b"); }};
    std::thread t4{[&]() { c.try_pop(); }};
    std::thread t5{[&]() { c.push("c"); }};
    std::thread t6{[&]() { c.try_pop(); }};
    std::thread t7{[&]() { c.try_pop(); }};
    std::thread t8{[&]() { c.push("d"); }};

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();

    auto y = c.try_pop();
    if (y)
    {
        std::cout << *y << std::endl;
    }
    else
    {
        std::cout << "empty" << std::endl;
    }
    y = c.try_pop();
    if (y)
    {
        std::cout << *y << std::endl;
    }
    else
    {
        std::cout << "empty" << std::endl;
    }

    return 0;
}
