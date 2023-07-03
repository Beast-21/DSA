#include <bits/stdc++.h>
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

        int val = this->data;

        if (this->next != NULL)
        {

            delete next;
            next = NULL;
        }
    }
};

void Print(Node *tail)
{

    Node *temp = tail;

    do
    {
        cout << temp->data << " ";
        temp = temp->next;

    } while (temp->next != tail);
}

void insertAtVal(Node *&tail, int val, int data)
{

    if (tail == NULL)
    {
        Node *node = new Node(data);
        tail = node;
        node->next = node;
    }

    else
    {

        Node *temp = tail;
        // Asumming val is present in the list;

        while (temp->data != val)
        {
            temp = temp->next;
        }
        Node *node = new Node(data);
        node->next = temp->next;
        temp->next = node;
    }

    return;
}

void deleteAtval(Node *&tail, int val)
{
    if (tail == NULL)
    {
        cout << "List is Empty  " << endl;
        return;
    }

    else
    {

        // Assuming val is in list;

        Node *pre = tail;
        Node *curr = tail->next;

        while (curr->data != val)
        {
            pre = curr;
            curr = curr->next;
        }
        pre->next = curr->next;
        curr->next = NULL;
        delete curr->next;
    }
}

int main()
{

    Node *tail = NULL;
    
    insertAtVal(tail, 10, 28);
    insertAtVal(tail, 28, 24);
    insertAtVal(tail, 24, 22);
    insertAtVal(tail, 22, 23);
    insertAtVal(tail, 23, 25);
    insertAtVal(tail, 25, 2);


     deleteAtval(tail, 25);

    Print(tail);

    return 0;
}