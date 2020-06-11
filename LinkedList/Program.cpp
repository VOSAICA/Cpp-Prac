#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};


node* create(int array[], int length)
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

int main()
{
    int array[10];
    for (int i = 0; i < 10; i++)
    {
        array[i] = i;
    }
    int length = sizeof(array) / sizeof(int);
    node* point = create(array, 10);
    point = point->next;
    while(point != NULL)
    {
        cout << point->data <<" "<< point << endl;
        point = point->next;
    }


    return 0;
}