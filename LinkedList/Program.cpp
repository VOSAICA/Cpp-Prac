#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *create(int array[], int length)
{
    node *cur, *pre, *head;
    head = new node;
    head->next = NULL;
    pre = head;
    for (int i = 0; i < length; i++)
    {
        cur = new node;
        cur->data = array[i];
        cur->next = NULL;
        pre->next = cur;
        pre = cur;
    }
    return head;
}

void insert(node *head, int pos, int x)
{
    node *cur = head;
    for (int i = 0; i < pos - 1; i++)
    {
        cur = cur->next;
    }
    node *insertNode = new node;
    insertNode->data = x;
    insertNode->next = cur->next;
    cur->next = insertNode;
}

void delPos(node *head, int pos)
{
    node *cur = head;
    node *del;
    for (int i = 0; i < pos - 1; i++)
    {
        cur = cur->next;
    }
    del = cur->next;
    cur->next = cur->next->next;
    delete (del);
}

int main()
{
    int array[10];
    for (int i = 0; i < 10; i++)
    {
        array[i] = i;
    }
    int length = sizeof(array) / sizeof(int);
    node *head = create(array, 10);

    node *point = head->next;
    while (point != NULL)
    {
        cout << point->data << " ";
        point = point->next;
    }
    cout << "\n\n";

    insert(head, 4, 676);
    delPos(head, 7);

    point = head->next;
    while (point != NULL)
    {
        cout << point->data << " ";
        point = point->next;
    }
    return 0;
}