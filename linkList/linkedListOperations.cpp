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

void insertAfter(struct Node *prevNode, int newData)
{
    if (prevNode == NULL)
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

void deleteNode(struct Node **headRef, int key)
{
    struct Node *temp = *headRef, *prev;

    if (temp != NULL && temp->data == key)
    {
        *headRef = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}

bool searchNode(struct Node **headRef, int key)
{
    struct Node *current = *headRef;

    while (current != NULL)
    {
        if (current->data == key)
            return true;
        current = current->next;
    }
    return false;
}

void printLinkList(struct Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout<<endl;
}

int main()
{
    struct Node *head = NULL;
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 5);
    insertAtEnd(&head, 7);
    insertAfter(head->next->next, 8);
    insertAfter(head->next->next, 3);
    deleteNode(&head, 4);

    printLinkList(head);

    searchNode(&head, 5) ? cout<<"Found"<<endl : cout<<"Not Found"<<endl;
    return 0;
}