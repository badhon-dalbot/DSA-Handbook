#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int value;
    struct Node *next;
};

void printLinkList(struct Node* head)
{
    while (head != NULL)
    {
        cout << head->value<<" ";
        head = head->next;
    }
}

int main()
{
    struct Node *one = new Node();
    struct Node *two = new Node();
    struct Node *three = new Node();
    struct Node *four = new Node();

    one->value = 10;
    two->value = 20;
    three->value = 30;
    four->value = 40;

    one->next = two;
    two->next = three;
    three->next = four;
    four->next = NULL;
    printLinkList(one);
    return 0;
}