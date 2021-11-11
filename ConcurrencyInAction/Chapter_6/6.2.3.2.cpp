#include <condition_variable>
#include <iostream>
#include <memory>
#include <mutex>
#include <thread>

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
    std::condition_variable data_cond;

    node* get_tail()
    {
        std::lock_guard<std::mutex> tail_lock(tail_mutex);
        return tail;
    }

    std::unique_ptr<node> pop_head()
    {
        std::unique_ptr<node> old_head = std::move(head);
        head = std::move(old_head->next);
        return old_head;
    }

    std::unique_ptr<node> try_pop_head()
    {
        std::lock_guard<std::mutex> head_lock(head_mutex);
        if (head.get() == get_tail())
        {
            return std::unique_ptr<node>{nullptr};
        }
        return pop_head();
    }

    std::unique_ptr<node> try_pop_head(T& value)
    {
        std::lock_guard<std::mutex> head_lock(head_mutex);
        if (head.get() == get_tail())
        {
            return std::unique_ptr<node>{nullptr};
        }
        value = std::move(*head->data);
        return pop_head();
    }

    std::unique_lock<std::mutex> wait_for_data()
    {
        std::unique_lock<std::mutex> head_lock(head_mutex);
        data_cond.wait(head_lock, [&] { return head.get() != get_tail(); });
        return head_lock;
    }

    std::unique_ptr<node> wait_pop_head()
    {
        std::unique_lock<std::mutex> head_lock(wait_for_data());
        return pop_head();
    }

    std::unique_ptr<node> wait_pop_head(T& value)
    {
        std::unique_lock<std::mutex> head_lock(wait_for_data());
        value = std::move(*head->data);
        return pop_head();
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

    bool try_pop(T& value);

    std::shared_ptr<T> wait_and_pop()
    {
        const std::unique_ptr<node> old_head = wait_pop_head();
        return old_head->data;
    }

    void wait_and_pop(T& value)
    {
        const std::unique_ptr<node> old_head = wait_pop_head(value);
    }

    void push(T new_value)
    {
        std::shared_ptr<T> new_data{std::make_shared<T>(std::move(new_value))};
        std::unique_ptr<node> new_node{std::make_unique<node>()};
        node* const new_tail = new_node.get();
        {
            std::lock_guard<std::mutex> tail_lock(tail_mutex);
            tail->data = new_data;
            tail->next = std::move(new_node);
            tail = new_tail;
        }
        data_cond.notify_one();
    }

    bool empty()
    {
        std::lock_guard<std::mutex> head_lock(head_mutex);
        return (head.get() == get_tail());
    }
};

int main()
{
    threadsafe_queue<int> q{};
    std::thread t1{[&]
                   {
                       for (int i = 0; i < 100; ++i)
                       {
                           q.push(i);
                       }
                   }};
    std::thread t2{[&]
                   {
                       for (int i = 0; i < 100; ++i)
                       {
                           q.push(i);
                       }
                   }};
    std::thread t3{[&]
                   {
                       for (int i = 0; i < 10; ++i)
                       {
                           q.wait_and_pop();
                       }
                   }};
    t1.join();
    t2.join();
    t3.join();
    while (!q.empty())
    {
        std::cout << *q.try_pop() << std::endl;
    }

    return 0;
}
