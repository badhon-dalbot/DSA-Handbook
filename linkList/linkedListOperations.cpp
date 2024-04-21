#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void insertAtBeginning(struct Node **head, int newData)
{
    struct Node *newNode = new Node();
    newNode->data = newData;
    newNode->next = *head;

    *head = newNode;
}

void insertAfter(struct Node *prevNode, int newData){
    if(prevNode == NULL)
    return;

    struct Node *newNode = new Node();
    newNode->data = newData;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void insertAtEnd(struct Node **head, int newData)
{
    struct Node *newNode = new Node();
    struct Node *last = *head;

    newNode->data = newData;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = newNode;
    return;
}



void printLinkList(struct Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    struct Node *head = NULL;
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 5);
    insertAtEnd(&head, 7);
    insertAfter(head->next->next, 8);

    printLinkList(head);
    return 0;
}