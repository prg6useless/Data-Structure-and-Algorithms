#include <iostream>

using namespace std;

class Tree
{
public:
    int data;
    Tree *left;
    Tree *right;
    Tree(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preorder(Tree *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Tree *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Tree *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int fun(Tree *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
        return 0;
    return 1 + fun(root->left) + fun(root->right);
}

// insertion and deletion remaining

int main()
{
    Tree *root = new Tree(1);
    root->left = new Tree(2);
    root->right = new Tree(3);
    root->left->left = new Tree(4);
    root->left->right = new Tree(5);
    root->right->left = new Tree(6);
    root->right->right = new Tree(7);

    /*
            1
           / \
          2   3
         / \ / \
        4  5 6  7
    */

    cout << "Number of nodes: " << fun(root) << endl;
    cout << "Preorder: ";
    preorder(root);
    cout << endl;
    cout << "Inorder: ";
    inorder(root);
    cout << endl;
    cout << "Postorder: ";
    postorder(root);
    return 0;
}
