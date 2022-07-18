/*
    Simple stack program
*/
#include <iostream>
using namespace std;

#define N 20

typedef struct stack{
    int a[N], top;
} stack;

int isEmpty(stack *s){
    return s->top == -1 ? 1 : 0;
}

void display(stack *s){
    if(isEmpty(s)){
        cout << "Stack empty" << endl;
    }
    else{
        cout << "Printing stack" << endl;
        // from top to 0
        for (int i = s->top; i >= 0;i--){
            cout << s->a[i] << endl;
        }
    }
}

void push(stack *s,int ele){
    if(s->top==N-1){
        cout << "Stack Full" << endl;
    }
    else{
        cout << "Inserted an element in stack" << endl;
        s->top++;
        s->a[s->top] = ele;
    }
}

void pop(stack *s)
{
    if (isEmpty(s))
    {
        cout << "Stack empty" << endl;
    }
    else
    {
        int x = s->a[s->top];
        s->top--;
        cout << "Popped element from stack is: " << x << endl;
    }
}

int main()
{
    int choice;
    stack s;
    s.top = -1;

    while (1)
    {
        cout << "\n-----------------" << endl
             << "Welcome to the Stack program." << endl
             << "Select any one operation to continue: \n"
             << "1. Display Stack \n2. Insert in Stack an element \n3. Pop an element from Stack \n4. Exit the program \n"
             << "-----------------" << endl;
        cin >> choice;

        if (choice == 4)
        {
            cout << "\nYou exited the program" << endl;
            break;
        }

        switch (choice)
        {

        case 1:
            display(&s);
            break;
        case 2:
            int element;
            cout << "Enter an element to add in queue:" << endl;
            cin >> element;
            push(&s, element);
            break;
        case 3:
            pop(&s);
            break;
        default:
            cout << "You entered a wrong choice. Please select again!!" << endl;
            break;
        }
    }

    return 0;
}
