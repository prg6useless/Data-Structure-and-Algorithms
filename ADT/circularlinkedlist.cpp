#include <iostream>

using namespace std;

/*Node is a block representing linked list which contains data and a pointer 'next' which points to the next Node*/

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtHead(Node *&head, int val)
{
    Node *n = new Node(val);
    /*since first node must be pointed to itself in the case of circular linked list*/
    if (head == NULL)
    {
        n->next = n;
        head = n;
        return;
    }

    Node *temp = head;
    /*traversng through the linked list*/
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n; /*last element is now pointed to our new element which we are trying to insert at head position*/
    n->next = head;
    head = n;
}

void insertAtTail(Node *&head, int val)
{
    Node *n = new Node(val);
    if (head == NULL)
    {
        insertAtHead(head, val);
        return;
    }
    Node *temp = head;
    /*traversng through the linked list to reach end of the linked list*/
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head; /*since its circular linked list, last element should point to the head*/
}

void display(Node *head)
{
    Node *temp = head;
    do
    {
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != head);
    cout << temp->data << "(head node)" << endl;
}

bool search(Node *head, int key)
{
    Node *temp = head;
    while (temp != head)
    {
        if (temp->data == key)
            return true;
        temp = temp->next;
    }
    return false;
}

void deleteAtHead(Node *&head)
{
    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    Node *todelete = head;
    temp->next = head->next;
    head = head->next;
    delete todelete;
}

void deletion(Node *&head, int val)
{
    if (head == NULL)
    {
        cout << "linked list is empty";
        return;
    }
    if (head->next == head)
    {
        deleteAtHead(head);
        return;
    }
    // Node *temp = head;
    // int count = 1;
    // while (count != pos - 1)
    // {
    //     temp = temp->next;
    //     count++;
    // }
    Node *temp = head;
    while (temp->next->data != val)
    {
        temp = temp->next;
    }
    Node *todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}

int main()
{
    Node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 5);
    insertAtTail(head, 4);
    display(head);
    insertAtHead(head, 7);
    display(head);
    deleteAtHead(head);
    display(head);
    deletion(head, 5); /*deletion of data in 3rd node*/
    display(head);
    search(head, 5) ? cout << "found" : cout << "Not found" << endl;
    return 0;
}