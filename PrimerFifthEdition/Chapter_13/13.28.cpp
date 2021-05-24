#include <iostream>
#include <string>

class TreeNode
{
public:
    TreeNode(const std::string& s = std::string("")) : value(s), count(new int(1)), left(nullptr), right(nullptr)
    {
    }

    TreeNode(const TreeNode& orgi) : value(orgi.value), count(orgi.count), left(orgi.left), right(orgi.right)
    {
        ++*count;
    }

    TreeNode& operator=(const TreeNode& rhs)
    {
        ++*rhs.count;
        if (--*count == 0)
        {
#ifndef NDEBUG
            std::cout << "deleting members\n";
#endif
            delete left;
            delete right;
        }
        value = rhs.value;
        count = rhs.count;
        left = rhs.left;
        right = rhs.right;

        return *this;
    }

    ~TreeNode()
    {
#ifndef NDEBUG
        std::cout << "~TreeNode()\n";
#endif
        if (--*count == 0)
        {
#ifndef NDEBUG
            std::cout << "deleting members\n";
#endif
            delete count;
            delete left;
            delete right;
        }
    }

private:
    std::string value;
    int* count;
    TreeNode* left;
    TreeNode* right;
};

class BinStrTree
{
public:
    BinStrTree() : root(new TreeNode())
    {
    }

    BinStrTree(const BinStrTree& orgi) : root(new TreeNode(*orgi.root))
    {
    }
    BinStrTree& operator=(const BinStrTree& rhs)
    {
        TreeNode* newRoot = new TreeNode(*rhs.root);
        delete root;
        root = newRoot;

        return *this;
    }
    ~BinStrTree()
    {
        delete root;
    }

private:
    TreeNode* root;
};

int main()
{
    auto a = TreeNode("SB");
    a = TreeNode("SB2");

    return 0;
}
