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

// counts sum of nodes
int SumNodes(Tree *root)
{
    if (root == NULL)
        return 0;
    return root->data + SumNodes(root->left) + SumNodes(root->right);
}

// counts no of nodes
int CountNodes(Tree *root)
{
    if (root == NULL)
        return 0;
    return 1 + CountNodes(root->left) + CountNodes(root->right);
}

// counts no of intenal nodes
int CountInternalNodes(Tree *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 0;
    return 1 + CountInternalNodes(root->left) + CountInternalNodes(root->right);
}

// insertion and deletion remaining

int main()
{
    // Tree *root = new Tree(1);

    // pastquestions pg 24
    Tree *root = new Tree(14);

    root->left = new Tree(2);
    root->right = new Tree(11);

    root->left->left = new Tree(1);
    root->left->right = new Tree(3);

    root->right->left = new Tree(10);
    root->right->right = new Tree(30);

    root->right->left->left = new Tree(7);
    root->right->right->left = new Tree(40);

    // root->left = new Tree(2);
    // root->right = new Tree(3);

    // root->left->left = new Tree(4);
    // root->left->right = new Tree(5);
    // root->right->left = new Tree(6);
    // root->right->right = new Tree(7);

    // root->left->left->left = new Tree(8);
    // root->left->left->right = new Tree(9);
    // root->left->right->left = new Tree(10);
    // root->left->right->right = new Tree(11);
    // root->right->left->left = new Tree(12);
    // root->right->left->right = new Tree(13);
    // root->right->right->left = new Tree(14);
    // root->right->right->right = new Tree(15);

    /*
                1
           /        \
          2           3
         /  \       /   \
        4    5     6     7
       / \  / \   / \   / \
      8  9 10 11 12 13 14 15
    */

    cout << "Number of nodes: " << CountInternalNodes(root) << endl;
    cout << "Preorder: ";
    preorder(root);
    cout << endl;
    cout << "Inorder: ";
    inorder(root);
    cout << endl;
    cout << "Postorder: ";
    postorder(root);
    cout << endl;
    cout << "Number of nodes: " << CountNodes(root) << endl;
    cout << "Sum of nodes: " << SumNodes(root) << endl;
    return 0;
}
