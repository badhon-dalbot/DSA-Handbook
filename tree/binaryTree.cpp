#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int value;
    struct Node *left, *right;
};
struct Node *newNode(int x)
{
    struct Node *node = new struct Node;

    node->value = x;
    node->left = node->right = NULL;
    return node;
}

struct Node *insert(struct Node *root, int value)
{
    if (root == NULL)
    {
        return newNode(value);
    }
    if (value < root->value)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }
}



void inorder(Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);

    cout << root->value << " ";

    inorder(root->right);
}

void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->value << " ";

    preorder(root->left);

    preorder(root->right);
}

struct Node *search(struct Node *root, int key)
{
    if (root == NULL || root->value == key)
        return root;

    if (root->value < key)
    {
        return search(root->right, key);
    }
    return search(root->left, key);
}
int main()
{
    struct Node *root = NULL;
     root= insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
     insert(root, 80);

    inorder(root);
    cout<<endl;
    preorder(root);

    return 0;
}