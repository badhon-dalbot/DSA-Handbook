#include <bits/stdc++.h>
using namespace std;

struct Node *find(struct Node *root, int key)
{
    if (root == NULL || root->value == key)
        return root;

    if (root->value < key)
    {
        return find(root->right, key);
    }
    return find(root->left, key);
}

int main()
{
    return 0;
}