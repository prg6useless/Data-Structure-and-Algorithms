#include <iostream>

using namespace std;

class LinkedList
{
public:
    int data;
    LinkedList *next;

    LinkedList(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtHead(LinkedList *&head, int val)
{

    LinkedList *n = new LinkedList(val);
    n->next = head;
    head = n;
}

void insertAtTail(LinkedList *&head, int val)
{

    LinkedList *n = new LinkedList(val);

    if (head == NULL)
    {
        head = n; /*inserted LinkedList is now head since there was no LinkedList initially*/
        return;
    }

    LinkedList *temp = head;
    /*for traversing through the linked list*/
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n; /*so, inserted at tail of the linked list*/
}

void insertAtPosition(LinkedList *&head, int val, int pos)
{
    LinkedList *n = new LinkedList(val);
    if (pos == 1)
    {
        n->next = head;
        head = n;
        return;
    }

    LinkedList *temp = head;
    for (int i = 0; i < pos - 2; i++)
    {
        temp = temp->next;
    }
    n->next = temp->next;
    temp->next = n;
}

bool search(LinkedList *head, int key)
{
    LinkedList *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
            return true;
        temp = temp->next;
    }
    return false;
}

void display(LinkedList *head)
{
    LinkedList *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

void deleteAtHead(LinkedList *&head)
{
    LinkedList *todelete = head;
    head = head->next;

    delete todelete;
}

void deletion(LinkedList *&head, int val)
{
    if (head == NULL)
    {
        cout << "Linked List is empty" << endl;
        return;
    }

    if (head->next == NULL)
    {
        deleteAtHead(head);
        return;
    }

    LinkedList *temp = head;
    while (temp->next->data != val)
    {
        temp = temp->next;
    }

    LinkedList *todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}

int main()
{
    LinkedList *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    display(head);
    deletion(head, 2);
    insertAtHead(head, 4);
    display(head);
    search(head, 7) ? cout << "found" : cout << "not found" << endl;
    deleteAtHead(head);
    display(head);
    insertAtPosition(head, 5, 2);
    display(head);
    return 0;
}