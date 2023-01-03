#include <iostream>
#define size 10
using namespace std;

int n = 10;
class Stack
{
public:
    int top;
    int items[size];

    Stack()
    {
        top = -1;
    }
};

void push(Stack *stack, int val)
{
    if (stack->top >= n - 1)
    {
        cout << "stack overflow" << endl;
    }
    else
    {
        (stack->top)++;
        stack->items[stack->top] = val;
    }
}

void pop(Stack *stack, int val)
{
    if (stack->top == -1)
        cout << "stack undeflow" << endl;
    else
    {
        cout << "poped element is " << stack->items[stack->top] << endl;
        (stack->top)--;
    }
}

void isEmpty(Stack *stack)
{
    if (stack->top == -1)
        cout << "stack is empty" << endl;
    else
        cout << "stack is not empty" << endl;
}

void stackTop(Stack *stack)
{
    if (stack->top == -1)
        cout << "stack is empty" << endl;
    else
        cout << "stack top is " << stack->items[stack->top] << endl;
}

void display(Stack *stack, int val)
{
    if (stack->top >= 0)
    {
        cout << "stack elements are:" << endl;
        for (int i = stack->top; i >= 0; i--)
        {
            cout << stack->items[i] << " ";
            cout << endl;
        }
    }
    else
        isEmpty(stack);
}

int main()
{
    Stack stack;
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
            push(&stack, val);
            break;
        }
        case 2:
        {
            pop(&stack, val);
            break;
        }
        case 3:
        {
            stackTop(&stack);
            break;
        }

        case 4:
        {
            display(&stack, val);
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
