#include <iostream>
using namespace std;

class Stack
{

    // properties

    int size;
    int *arr;
    int top;

public:
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    int push(int val)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = val;

            return 0;
        }

        else
        {

            cout << " stack Overflow" << endl;
            return -1;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << " Stack UNderflow " << endl;
            return;
        }

        else
        {
            top--;
            return;
        }
    }

    bool isEmpty()
    {

        if (top == -1)
        {
            return true;
        }

        return false;
    }

    int peek()
    {

        if (top != -1)
        {
            return arr[top];
        }

        else
        {
            cout << " stack is underflow" << endl;
            return -1;
        }
    }
};

int main()
{

    Stack s(5);

    s.push(2);
    s.push(4);
    s.push(5);
    s.push(6);

    cout << s.peek() << endl;
    s.pop();
    cout << s.peek() << endl;

    s.pop();
    cout << s.peek() << endl;

    s.pop();
    cout << s.peek() << endl;

    s.pop();
    cout << s.peek() << endl;

    if (s.isEmpty())
    {
        cout << " stack is empty " << endl;
    }

    return 0;
}