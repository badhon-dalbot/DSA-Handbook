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

bool find(struct Node *root, int key)
{
    if (root == NULL)
        return false;
    if (root->data == key)
        return true;

    if (root->data < key)
    {
       return find(root->right, key);
    }
   return find(root->left, key);
}

struct Node *successor(Node *root)
{
    Node *current = root;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

struct Node *deleteNode(struct Node *root, int key)
{
    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            Node *temp = successor(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
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

int height(Node *root){
    if(root == NULL) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
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
    insert(root, 37);
    insert(root, 38);
    insert(root, 24);

    printInOrder(root);
    cout << endl;
    cout<<height(root)<<endl;
    printPreOrder(root);
    cout << endl;
    printPostOrder(root);
    cout << endl;
    deleteNode(root, 22);
    deleteNode(root, 48);
    deleteNode(root, 40);
    printInOrder(root);
    cout<<endl;

    cout<< find(root,40);
    Node * succ = successor(root);
    cout<<endl;
    cout<<height(root);
    return 0;
}