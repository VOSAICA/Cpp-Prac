#include<iostream>
using namespace std;

struct node{
    int data;
    node* lchild;
    node* rchild;
};

node* newNode(int v)
{
    node* Node = new node;
    Node->data = v;
    Node->lchild = Node->rchild = NULL;
    return Node;
}

void insert(node* &root, int x)
{
    if (root == NULL)
    {
        root = newNode(x);
        return;
    }
    if (root->lchild == NULL)
    {
        insert(root->lchild, x);
    }
    else
    {
        insert(root->rchild, x);
    }
}

node* create(int data[], int n)
{
    node* root = NULL;
    for (int i = 0; i < n; i++)
    {
        insert(root, data[i]);
    }
    return root;
}

void preorder(node* root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << endl;
    preorder(root->lchild);
    preorder(root->rchild);
}

void inorder(node* root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->lchild);
    cout << root->data << endl;
    inorder(root->rchild);
}

void postorder(node* root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->lchild);
    postorder(root->rchild);
    cout << root->data << endl;
}

int main()
{
    int array[5] = {3, 4, 5, 1, 2};
    node* head = create(array, 5);

    preorder(head);


    return 0;
}