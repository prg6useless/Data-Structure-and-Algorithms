#include <iostream>

using namespace std;

int top = -1, n = 10;

void push(int stack[], int val)
{
    if (top >= n - 1)
        cout << "Stack Overflow" << endl;
    else
    {
        top++;
        stack[top] = val;
    }
}

void pop(int stack[], int val)
{
    if (top <= -1)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        cout << "The popped element is " << stack[top] << endl;
        top--;
    }
}

void isEmpty(int stack[])
{
    if (top == -1)
        cout << "Stack is empty" << endl;
    else
        cout << "Stack is not empty" << endl;
}

void StackTop(int stack[])
{
    if (top == -1)
        isEmpty(stack);
    else
        cout << "Stack top is " << stack[top] << endl;
}

void display(int stack[])
{
    if (top >= 0)
    {
        cout << "stack elements are:" << endl;
        for (int i = top; i >= 0; i--)
        {
            cout << stack[i] << " ";
            cout << endl;
        }
    }
    else
        isEmpty(stack);
}

int main()
{
    int stack[10], n = 10;
    int ch, val;

    cout << "1) Push in stack" << endl;
    cout << "2) Pop from stack" << endl;
    cout << "3) Display stack top item" << endl;
    cout << "4) Display stack" << endl;
    cout << "5) Exit" << endl;
    do
    {
        cout << "Enter choice: " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "Enter value to be pushed:";
            cin >> val;
            push(stack, val);
            break;
        }
        case 2:
        {
            pop(stack, val);
            break;
        }
        case 3:
        {
            StackTop(stack);
            break;
        }

        case 4:
        {
            display(stack);
            break;
        }

        case 5:
        {
            cout << "Exit";
            break;
        }

        default:
        {
            cout << "Invalid choice" << endl;
            break;
        }
        }
    } while (ch != 5);
    return 0;
}
