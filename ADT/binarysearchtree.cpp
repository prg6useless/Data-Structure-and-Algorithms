#include <iostream>

using namespace std;

class BST
{
public:
    int data;
    BST *left;
    BST *right;
    BST(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool search(BST *root, int key)
{
    if (root == NULL)
        return false;
    if (root->data == key)
        return true;
    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

BST *insertBST(BST *root, int val)
{
    if (root == NULL)
        return new BST(val);
    if (val < root->data)
        root->left = insertBST(root->left, val);
    else
        // val > root->data
        root->right = insertBST(root->right, val);
    return root;
}

BST *inorderSucc(BST *root)
{
    BST *current = root;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

BST *deleteBST(BST *root, int key)
{
    if (key < root->data)
    {
        root->left = deleteBST(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteBST(root->right, key);
    }
    else
    {
        // case 2: if node has a single child
        // if single child is on left
        if (root->left == NULL)
        {
            BST *temp = root->right;
            free(root);
            return temp;
        }
        // if single child is on right
        else if (root->right == NULL)
        {
            BST *temp = root->left;
            free(root);
            return temp;
        }
        // case 3 : node has two children
        BST *temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteBST(root->right, temp->data);
    }
    return root;
}

void inorderDisplay(BST *root)
{
    if (root == NULL)
        return;

    inorderDisplay(root->left);
    cout << root->data << " ";
    inorderDisplay(root->right);
}

int main()
{
    BST *root = NULL;
    root = insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 7);
    search(root, 3)
        ? cout << "Found" << endl
        : cout << "Not Found" << endl;
    inorderDisplay(root);
    deleteBST(root, 3);
    cout << endl;
    inorderDisplay(root);
    return 0;
}
