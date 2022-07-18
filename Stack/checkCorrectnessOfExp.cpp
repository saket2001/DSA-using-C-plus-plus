/*
    Simple stack program for checking correctness of exp
    Expressions-
    1) (a+b)+c -> valid
    2) {(a+b)-c} -> valid
    3) (a-b} -> invalid
*/
#include <iostream>
#include <string.h>
using namespace std;
#define N 30

typedef struct stack
{
    string a[N];
    int top;
} stack;

int isEmpty(stack *s)
{
    return s->top == -1 ? 1 : 0;
}

void display(stack *s)
{
    if (isEmpty(s))
    {
        cout << "Stack empty" << endl;
    }
    else
    {
        cout << "Printing stack" << endl;
        // from top to 0
        for (int i = s->top; i >= 0; i--)
        {
            cout << s->a[i];
        }
        cout << endl;
    }
}

void push(stack *s, string ele)
{
    if (s->top == N - 1)
    {
        cout << "Stack Full" << endl;
    }
    else
    {
        s->top++;
        s->a[s->top] = ele;
    }
}

string pop(stack *s)
{
    string x;
    if (isEmpty(s))
    {
        cout << "Stack empty" << endl;
    }
    else
    {
        x = s->a[s->top];
        s->top--;
    }
    return x;
}

int isOpenBracket(string x){
    if(x=="(" || x=="{" || x=="["){
        return 1;
    }
    else{
        return 0;
    }
}

int isClosingBracket(string x)
{
    if (x == ")" || x == "}" || x == "]")
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int validateExpression(string str){
    string x,ele;
    stack s;
    s.top = -1;
    for (int i = 0; i <=str.length();i++){
        x = str[i];
        // 
        if(isOpenBracket(x)){
            push(&s, x);
        }
        if(isClosingBracket(x)){
            // pop an element
            ele = pop(&s);
            if(ele=="(" && x==")"){
                return 1;
            }
            if(ele=="{" && x=="}"){
                return 1;
            }
            if(ele=="[" && x=="]"){
                return 1;
            }
        }
    }
    if (isEmpty(&s))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    string expression;

    while (1)
    {
        cout << "Welcome to the Stack program for checking correctness of expression" << endl << "Enter your Expression:";

        getline(cin,expression);

        if (validateExpression(expression))
        {
            cout << "Valid Expression" << endl;
        }
        else{
            cout << "Not Valid Expression" << endl;
        }
    }
    return 0;
}
