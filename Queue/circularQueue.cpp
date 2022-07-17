/*
    Circular queue program using C++
*/
#include <iostream>
using namespace std;

#define N 20
typedef struct queue
{
    int a[N], front, rear, count;
} queue;

int isEmpty(queue *q)
{
    return q->count == 0 ? 1 : 0;
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
        int i = q->front;
        while (1)
        {
            cout << q->a[i] << "\t";
            if (i == q->rear)
            {
                break;
            }
            else
            {
                i = (i + 1) % N;
            }
        }
    }
}

void enqueue(queue *q, int ele)
{
    if (q->count == N)
    {
        cout << "Queue overflow" << endl;
    }
    else
    {
        cout << "Inserting in queue" << endl;
        q->count++;
        q->rear = (q->rear + 1) % N;
        q->a[q->rear] = ele;
        display(q);
    }
}

void pop(queue *q)
{
    if (isEmpty(q))
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        q->count--;
        int x = q->a[q->front];
        q->front = (q->front + 1) % N;
        cout << "Popped element from queue: " << x << endl;
        display(q);
    }
}

int main()
{
    int choice, element;
    queue q;
    q.rear = -1;
    q.front = q.count = 0;

    while (1)
    {
        cout << "\n-----------------" << endl
             << "Welcome to Circular Queue program." << endl
             << "Select any one operation to continue: \n"
             << "1. Display Queue \n2. Insert in queue an element \n3. Pop an element from queue \n4. Exit the program \n"
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
            display(&q);
            break;
        case 2:
            cout << "Enter an element to add in queue:" << endl;
            cin >> element;
            enqueue(&q, element);
            break;
        case 3:
            pop(&q);
            break;
        default:
            cout << "You entered a wrong choice. Please select again!!" << endl;
            break;
        }
    }

    return 0;
}