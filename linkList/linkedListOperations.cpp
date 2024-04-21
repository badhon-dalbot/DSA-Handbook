#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};
void insertAtBeginning(struct Node **head, int newData)
{
    struct Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = *head;

    *head = newNode;
}

void printLinkList(struct Node* head)
{
    while (head != NULL)
    {
        cout << head->data<<" ";
        head = head->next;
    }
}


int main()
{
    struct Node* head = NULL;
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 5);

    printLinkList(head);
    return 0;
}