#include <iostream>
#include <queue>
using namespace std;

struct node
{
    int data;
    node *lchild;
    node *rchild;
};

node *newNode(int v)
{
    node *Node = new node;
    Node->data = v;
    Node->lchild = Node->rchild = NULL;
    return Node;
}

void insert(node *&root, int x)
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

node *create(int data[], int n)
{
    node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        insert(root, data[i]);
    }
    return root;
}

void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << endl;
    preorder(root->lchild);
    preorder(root->rchild);
}

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->lchild);
    cout << root->data << endl;
    inorder(root->rchild);
}

void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->lchild);
    postorder(root->rchild);
    cout << root->data << endl;
}

void layerorder(node *root)
{
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *now = q.front();
        cout << now->data << endl;
        if (now->lchild != NULL)
        {
            q.push(now->lchild);
        }
        if (now->rchild != NULL)
        {
            q.push(now->rchild);
        }
        q.pop();
    }
}

node *recreate(int preL, int preR, int inL, int inR, int pre[], int in[])
{
    if (preL > preR)
        return NULL;
    node *root = new node;
    root->data = pre[preL];
    int k;
    for (k = inL; k <= inR; k++)
    {
        if (in[k] == pre[preL])
            break;
    }
    int numLeft = k - inL;

    root->lchild = recreate(preL + 1, preL + numLeft, inL, k - 1, pre, in);
    root->rchild = recreate(preL + numLeft + 1, preR, k + 1, inR, pre, in);
    return root;
}

int main()
{
    int array[8] = {3, 4, 5, 1, 2, 7, 9, 0};
    node *head = create(array, 8);

    preorder(head);
    cout << endl;
    inorder(head);
    cout << endl;
    postorder(head);
    cout << endl;

    int pre[8] = {3, 4, 1, 2, 5, 7, 0, 9};
    int in[8] = {1, 4, 2, 3, 0, 7, 5, 9};
    node *head2 = recreate(0, 7, 0, 7, pre, in);
    layerorder(head2);
    return 0;
}