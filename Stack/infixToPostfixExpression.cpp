/*
    Simple stack program for converting infix exp
    to postfix -
    infix-> a+b
    postfix -> ab+
*/

// !Error : Need to make it correct

#include <iostream>
#include <string.h>
using namespace std;
#define N 30

typedef struct stack
{
    char a[N];
    int top;
} stack;

int isEmpty(stack *s)
{
    return s->top == -1 ? 1 : 0;
}

void push(stack *s, char ele)
{
    s->top++;
    s->a[s->top] = ele;
}

char pop(stack *s)
{
    char x;
    x = s->a[s->top];
    s->top--;
    return x;
}

char getStackTop(stack *s)
{
    return s->a[s->top];
}

int isOpenBracket(char x)
{
    if (x == '(' || x == '{' || x == '[')
        return 1;
    else
        return 0;
}

int isOperand(char x)
{
    if (x >= 'A' && x <= 'Z' || x >= 'a' && x <= 'z')
        return 1;
    else
        return 0;
}

int isOperator(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '-' || x == '^')
        return 1;
    else
        return 0;
}

int getPriority(char x)
{
    if (x == '^')
        return 4;
    else if (x == '*' || x == '/')
        return 3;
    else if (x == '+' || x == '-')
        return 2;
    else
        return 1;
}

int isClosingBracket(char x)
{
    if (x == ')' || x == '}' || x == ']')
        return 1;
    else
        return 0;
}

char* validateExpression(char infix[], char postfix[])
{
    char x, ele;
    stack s;
    s.top = -1;
    int k = 0;
    for (int i = 0; i <= strlen(infix); i++)
    {
        x = infix[i];
        //
        if (isOperand(x))
            postfix[k++] = x;
        else if (isOpenBracket(x))
            push(&s, x);
        else if (isOperator(x))
        {
            while (getPriority(x) <= getPriority(getStackTop(&s)))
            {
                // pop an element
                ele = pop(&s);
                postfix[k++] = ele;
            }
            push(&s, x);
        }
        else
        {
            while (x != '(')
            {
                // pop an element
                ele = pop(&s);
                postfix[k++] = ele;
            }
            ele = pop(&s);
        }
    }
    while (isEmpty(&s) != 0)
    {
        // pop an element
        ele = pop(&s);
        postfix[k++] = ele;
    }
    postfix[k] = '\0';
    return postfix;
}

int main()
{
    char infix[30], postfix[30];

    while (1)
    {
        cout << "\nSimple stack program for converting infix exp to postfix" << endl
             << "Enter your infix Expression:";
        cin >> infix;

        cout << "-----------" << endl;
        cout << "You entered: " << infix << endl;

        validateExpression(infix, postfix);
        cout << "Postfix Expression: " << postfix << endl;
    }
    return 0;
}
