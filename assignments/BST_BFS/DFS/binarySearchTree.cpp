#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *newNode(int key)
{
    struct Node *node = new struct Node;

    node->data = key;
    node->left = node->right = NULL;
    return node;
}

struct Node *find(struct Node *root, int key)
{
    if (root == NULL || root->data == key)
        return root;

    if (root->data < key)
    {
        return find(root->right, key);
    }
    return find(root->left, key);
}


struct Node *insert(struct Node *root, int key)
{
    if (root == NULL)
    {
        return newNode(key);
    }
    if (key < root->data)
    {
        root->left = insert(root->left, key);
    }
    else
    {
        root->right = insert(root->right, key);
    }
    return root;
}

void printInOrder(Node *root)
{
    if (root == NULL)
        return;

    printInOrder(root->left);

    cout << root->data << " ";

    printInOrder(root->right);
}

void printPreOrder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";

    printPreOrder(root->left);

    printPreOrder(root->right);
}

void printPostOrder(Node *root)
{
    if (root == NULL)
        return;

    printPostOrder(root->left);

    printPostOrder(root->right);

    cout << root->data << " ";
}
int main()
{
    struct Node *root = NULL;
    root = insert(root, 22);
    insert(root, 18);
    insert(root, 10);
    insert(root, 15);
    insert(root, 36);
    insert(root, 40);
    insert(root, 48);
    insert(root, 51);

    printInOrder(root);
    cout<<endl;
    printPreOrder(root);
    cout<<endl;
    printPostOrder(root);
    return 0;
}