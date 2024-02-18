#include <iostream>
#include <stack>
#include <cmath>
#include <string>

using namespace std;

struct Node
{
    string info;
    Node *pNext;
};

Node *createNode(string info)
{
    Node *newNode = new Node;
    newNode->info = info;
    newNode->pNext = NULL;
    return newNode;
}

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == 'd' || c == '^');
}

int getPriority(string op)
{
    if (op == "^")
        return 3;
    else if (op == "*" || op == "/" || op == "div")
        return 2;
    else if (op == "+" || op == "-")
        return 1;
    else
        return 0;
}

string infixToPostfix(string infix)
{
    stack<string> opStack;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] == ' ')
            continue;
        else if (isdigit(infix[i]))
        {
            string num = "";
            while (i < infix.length() && isdigit(infix[i]))
                num += infix[i++];
            i--;
            postfix += num + " ";
        }
        else if (isOperator(infix[i]))
        {
            string op = "";
            op += infix[i];
            while (!opStack.empty() && isOperator(opStack.top()[0]) && getPriority(op) <= getPriority(opStack.top()))
            {
                postfix += opStack.top() + " ";
                opStack.pop();
            }
            opStack.push(op);
        }
        else if (infix[i] == '(')
        {
            opStack.push("(");
        }
        else if (infix[i] == ')')
        {
            while (!opStack.empty() && opStack.top() != "(")
            {
                postfix += opStack.top() + " ";
                opStack.pop();
            }
            opStack.pop();
        }
        else
        {
            string func = "";
            while (i < infix.length() && isalpha(infix[i]))
                func += infix[i++];
            i--;
            opStack.push(func);
        }
    }

    while (!opStack.empty())
    {
        postfix += opStack.top() + " ";
        opStack.pop();
    }

    return postfix;
}

double evaluatePostfix(string postfix)
{
    stack<double> operandStack;
    for (int i = 0; i < postfix.length(); i++)
    {
        if (postfix[i] == ' ')
            continue;
        else if (isdigit(postfix[i]))
        {
            double num = 0;
            while (i < postfix.length() && isdigit(postfix[i]))
            {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            i--;
            operandStack.push(num);
        }
        else if (isOperator(postfix[i]))
        {
            double op2 = operandStack.top();
            operandStack.pop();
            double op1 = operandStack.top();
            operandStack.pop();
            switch (postfix[i])
            {
            case '+':
                operandStack.push(op1 + op2);
                break;
            case '-':
                operandStack.push(op1 - op2);
                break;
            case '*':
                operandStack.push(op1 * op2);
                break;
            case '/':
                operandStack.push(op1 / op2);
                break;
            case 'd':
                operandStack.push((int)op1 % (int)op2);
                break;
            case '^':
                operandStack.push(pow(op1, op2));
                break;
            }
        }
        else
        {
            string func = "";
            while (i < postfix.length() && isalpha(postfix[i]))
            {
                func += postfix[i];
                i++;
            }
            i--;
            double arg = operandStack.top();
            operandStack.pop();
            if (func == "sin")
                operandStack.push(sin(arg));
            else if (func == "cos")
                operandStack.push(cos(arg));
            else if (func == "tan")
                operandStack.push(tan(arg));
            else if (func == "ln")
                operandStack.push(log(arg));
            else if (func == "ex")
                operandStack.push(exp(arg));
        }
    }

    return operandStack.top();
}

int main()
{
    string infix;
    cout << "Nhap bieu thuc: ";
    getline(cin, infix);
    string postfix = infixToPostfix(infix);
    cout << postfix << endl;
    double result = evaluatePostfix(postfix);
    cout << "Ket qua: " << result << endl;
    return 0;
}
