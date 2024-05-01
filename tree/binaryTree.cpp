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

struct Node *search(struct Node *root, int key){
    if(root == NULL || root->value == key)
    return root;

    if(root->value < key){
        return search(root->right, key);
    }
    return search(root->left, key);
}
int main()
{
    struct Node *root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->left = newNode(6);
    root->left->right->right = newNode(7);

    (search(root, 8) != NULL) ? 
    cout<<"Found": cout<<"Not Found";

    return 0;
}