/*
    Doubly ended queue program using C++
*/
#include <iostream>
using namespace std;

#define N 20
typedef struct queue
{
    int a[N], front, rear;
} queue;

int isEmpty(queue *q)
{
    return q->front == q->rear ? 1 : 0;
}

void display(queue *q)
{
    if (isEmpty(q))
    {
        cout << "Queue is empty" << endl;
    }
    else
    {

        cout << "Queue is being printed" << endl;
        for (int i = q->front+1; i <= q->rear; i++)
        {
            cout << q->a[i] << "\t";
        }
    }
}

void insertLeft(queue *q,int ele){
    // uses front
     if (q->front == -1)
    {
        cout << "Queue overflow" << endl;
    }
    else
    {
        cout << "Inserting in queue from left side" << endl;
        q->a[q->front] = ele;
        q->front--;
        display(q);
    }
}

void insertRight(queue *q, int ele)
{
    if (q->rear == N - 1)
    {
        cout << "Queue overflow" << endl;
    }
    else
    {
        cout << "Inserting in queue from right side" << endl;
        q->rear++;
        q->a[q->rear] = ele;
        display(q);
    }
}

void popLeft(queue *q)
{
    if (isEmpty(q))
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        q->front++;
        int x = q->a[q->front];
        cout << "Popped left side element from queue: " << x << endl;
    }
}

void popRight(queue *q)
{
    if (isEmpty(q))
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        int x = q->a[q->rear];
        cout << "Popped right side element from queue: " << x << endl;
        q->rear--;
    }
}

int main()
{
    int choice, element;
    queue q;
    q.rear = q.front= N / 2;

    while (1)
    {
        cout << "\n-----------------" << endl
             << "Welcome to queue program." << endl
             << "Select any one operation to continue: \n"
             << "1. Display Queue \n2. Insert in queue an element from left \n3. Insert in queue an element from right \n4. Pop an left side element from queue \n5. Pop an right side element from queue \n6. Exit the program \n"
             << "-----------------" << endl;
        cin >> choice;

        if (choice == 6)
        {
            cout << "\nYou exited the program" << endl;
            break;
        }

        switch (choice)
        {

        case 1:
            display(&q);
            break;
        case 2:
            cout << "Enter an element to add in queue:" << endl;
            cin >> element;
            insertLeft(&q, element);
            break;
        case 3:
            cout << "Enter an element to add in queue:" << endl;
            cin >> element;
            insertRight(&q, element);
            break;
        case 4:
            popLeft(&q);
            break;
        case 5:
            popRight(&q);
            break;
        default:
            cout << "You entered a wrong choice. Please select again!!" << endl;
            break;
        }
    }

    return 0;
}