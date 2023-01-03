#include <iostream>

using namespace std;

int rear = -1, front = -1;

int maxQueueSize = 10;

void enqueue(int queue[], int value) /*enqueue = insert*/
{
    if (rear == maxQueueSize - 1)
    {
        cout << "queue overflow";
        cout << endl;
    }
    else
    {
        if (front == -1)
            front = 0;
        rear += 1;
        queue[rear] = value;
    }
}

void dequeue(int queue[]) /*dequeue = delete*/
{
    if (rear == front)
    {
        cout << "queue underflow";
        cout << endl;
    }
    else
    {
        cout << "element removed is " << queue[front];
        front += 1;
    }
}

void display(int queue[])
{
    if (front == -1)
    {
        cout << "queue is empty";
        cout << endl;
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            cout << "element " << i + 1 << " = " << queue[i] << endl;
        }
    }
}

int main()
{
    int ch;
    int queue[10];
    cout << "1. Insert value? " << endl;
    cout << "2. delete value? " << endl;
    cout << "3. display value? " << endl;
    cout << "4. exit? " << endl;

    do
    {
        cout << "choice?" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            int value;
            cout << "enter value : " << endl;
            cin >> value;
            enqueue(queue, value);
            break;
        }
        case 2:
            dequeue(queue);
            break;
        case 3:
            display(queue);
            break;
        case 4:
            cout << "exit" << endl;
            break;
        default:
            cout << "error";
            cout << endl;
            break;
        }
    } while (ch != 4);
}
