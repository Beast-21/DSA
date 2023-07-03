#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)

    {

        this->data = d;
        this->next = NULL;
    }

    ~Node()
    {

        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }

        cout << "MEMORY IS FREED" << endl;
    }
};

void insertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void Print(Node *&Head)
{

    Node *temp = Head;
    while (temp != NULL)
    {
        cout << temp->data << "  ";
        temp = temp->next;
    }

    cout<<endl;
}

Node *TAIL(Node *&head)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    return temp;
}

void insertAtTail(Node *&head, int data)
{
    Node *tail = TAIL(head);
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void insertAtPostion(Node *&head, int pos, int data)
{

    Node *temp = head;
    int cnt = 1;

    while (cnt > pos)
    {
        temp = temp->next;
        cnt++;
    }

    Node *posnode = new Node(data);
    posnode->next = temp->next;
    temp->next = posnode;
}

void insertAfterValue(Node *&head, int data)
{

    Node *temp = head;
    Node *curr = new Node(data);

    while (temp->data != data)
    {
        temp = temp->next;
    }
}

void deleteNode(Node *head, int Position)
{

    if (Position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    else
    {

        Node *prev = NULL;
        Node *curr = head;

        int cnt = 1;

        while (cnt < Position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main()

{

    int d = 2;

    Node *node = new Node(d);
    Node *head = node;

    insertAtHead(head, 12);
    insertAtHead(head, 13);

    insertAtTail(head, 14);
    insertAtPostion(head, 2, 16);

    Print(head);

    deleteNode(head, 3);

    Print(head);

    return 0;
}