#include <iostream>
#include <stack>
#include <math.h>

using namespace std;

float EvaluatePostfix(string exp)
{
    stack<float> s;
    for (int i = 0; i < exp.length(); i++)
    {
        // if expression is an operand
        if (exp[i] >= '0' && exp[i] <= '9')
            s.push(exp[i] - '0');
        else // if expression is an operator
        {
            float operand2 = s.top();
            s.pop();
            float operand1 = s.top();
            s.pop();
            switch (exp[i])
            {
            case '+':
                s.push(operand1 + operand2);
                break;
            case '-':
                s.push(operand1 - operand2);
                break;
            case '*':
                s.push(operand1 * operand2);
                break;
            case '/':
                s.push(operand1 / operand2);
                break;
            case '^':
                s.push(pow(operand1, operand2));
                break;
            }
        }
    }
    return s.top();
}

float EvaluatePrefix(string exp)
{
    stack<float> s;
    for (int i = exp.length() - 1; i >= 0; i--)
    {
        if (exp[i] >= '0' && exp[i] <= '9')
            s.push(exp[i] - '0');
        else
        {
            float operand1 = s.top();
            s.pop();
            float operand2 = s.top();
            s.pop();
            switch (exp[i])
            {
            case '+':
                s.push(operand1 + operand2);
                break;
            case '-':
                s.push(operand1 - operand2);
                break;
            case '*':
                s.push(operand1 * operand2);
                break;
            case '/':
                s.push(operand1 / operand2);
                break;
            case '^':
                s.push(pow(operand1, operand2));
                break;
            }
        }
    }
    return s.top();
}

int main()
{
    string postfixexp = "345-2*/";
    string prefixexp = "-+8/632";
    cout << "postfix evaluation: " << EvaluatePostfix(postfixexp);
    cout << endl;
    cout << "prefix evaluation: " << EvaluatePrefix(prefixexp);
    return 0;
}