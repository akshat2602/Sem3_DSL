#include <iostream>
using namespace std;

class Stack
{

private:
    int size;
    int top;
    char *arr;

public:
    Stack()
    {
        size = 100;
        top = -1;
        arr = new char[size];
    }
    int isFull()
    {
        if (top == size - 1)
        {
            return 1;
        }
        return 0;
    }

    int isempty()
    {
        if (top == -1)
        {
            return 1;
        }
        return 0;
    }

    void push(char data)
    {
        if (isFull() == 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        top = top + 1;
        arr[top] = data;
    }

    char pop()
    {
        if (isempty() == 1)
        {
            return -1;
        }

        char m = arr[top];
        top--;
        return m;
    }

    char topEle()
    {
        return arr[top];
    }
};

class Expression
{
    char exp[100];
    Stack *sp = new Stack();

public:
    void input()
    {
        cout << "Enter the expression : ";
        cin >> exp;
    }

    bool check()
    {

        for (int i = 0; i <= sizeof(exp); i++)
        {
            if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            {
                sp->push(exp[i]);
                continue;
            }

            char x;
            switch (exp[i])
            {
            case ')':
                x = sp->topEle();
                sp->pop();
                if (x == '[' || x == '{')
                {
                    return false;
                }
                break;

            case '}':
                x = sp->topEle();
                sp->pop();
                if (x == '[' || x == '(')
                {
                    return false;
                }
                break;
            case ']':
                x = sp->topEle();
                sp->pop();
                if (x == '(' || x == '{')
                {
                    return false;
                }
                break;

            default:
                break;
            }
        }

        if (sp->isempty() == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{

    Expression expr;
    expr.input();
    if (expr.check())
    {
        cout << "Parenthesis are mathcing in the given expression" << endl;
    }
    else
    {
        cout << "Parenthesis are NOT mathcing in the given expression" << endl;
    }

    return 0;
}