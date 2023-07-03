

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int d)
    {

        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node()
    {
        int val = this->data;
        if(this->next!=NULL){

            delete next;
            next=NULL;
            
        }
        cout<<val<<" VAL is Deleted"<<endl;
    }
};

void Print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int getLength(Node *head)
{
    Node *temp = head;

    int cnt = 0;

    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }

    cout << endl;

    return cnt;
}

void insertAtHead(Node *&head, int data)
{
    Node *temp = head;
    Node *node = new Node(data);
    node->next = head;
    head->prev = node;
    head = node;
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

void insertAtTAil(Node *&head, int data)
{

    Node *tail = TAIL(head);
    Node *node = new Node(data);
    tail->next = node;
    node->prev = tail;
    tail = node;
}

void insertAtPos(Node * &Head, int pos, int data)
{       

    if(pos>getLength(Head))
    {
        cout<<"Enter valid position"<<endl;
        return;

    }
    if(pos==1){

        insertAtHead(Head , data);
        return;
    }


    
    Node *temp = Head;

    
    int cnt = 1;

    while (cnt < pos-1)
    {
        temp = temp->next;
        cnt++;
    }


    if(temp->next == NULL)
    {
        insertAtTAil(Head , data);
        return ;
    }
    Node *temp_1 = temp->next;
    Node *node = new Node(data);
    node->next = temp->next;
    temp->next = node;
    node->prev = temp;
    temp_1->prev = node;
}

void PrintRevrse(Node * &head){

    
    Node* tail = TAIL(head);
    Node * temp = tail;

    while(temp!=NULL)
    {
        cout<<temp->data<<"  ";
        temp = temp->prev;
    }

    cout<<endl;

}


void deleteAthead(Node * head)
{
        Node * temp = head;
        temp->next = head;
         temp->next->prev=NULL;
         temp->next=NULL;
         delete temp;

         
}

void deleteAtPos(Node * & head , int pos)
{
    if(pos == 1)
    {
        deleteAthead(head);
        return;

    }

    else{
            Node * pre = NULL;
            Node * curr = head;

            int cnt = 1;
            while(cnt < pos){

                pre = curr;
                curr = curr->next;
                cnt++;
            }

            pre->next = curr->next;
            curr->next->prev = pre;
            curr->next = NULL;
            curr->prev = NULL;
            delete curr;





    }

    return;
}
int main()
{
    Node *node = new Node(10);
    Node *head = node;

    insertAtHead(head, 12);

    insertAtTAil(head, 14);
    insertAtTAil(head, 17);
    insertAtPos(head , 3 ,11);
    Print(head);


    deleteAtPos(head , 3);

    Print(head);
    //PrintRevrse(head);

    return 0;
}
