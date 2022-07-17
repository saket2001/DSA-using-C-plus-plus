/*
    Simple queue program using C++
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
    return q->front == q->rear + 1 || q->rear == -1 ? 1 : 0;
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
        for (int i = q->front; i <= q->rear; i++)
        {
            cout << q->a[i] << "\t";
        }
    }
}

void enqueue(queue *q, int ele)
{
    if (q->rear == N - 1)
    {
        cout << "Queue overflow" << endl;
    }
    if(q->rear==-1){
        q->rear++;
        q->a[q->rear] = ele;
        display(q);
    }
    else
    {
        // insert bigger element first and later lower i.e [10,6,2]
        // step1 find max position
        int i;
        for (i = q->front; i <= q->rear;i++){
            if(ele>q->a[i]){
                break;
            }
        }
        cout << i << endl;
        // step2 arrange items in desc
        for (int j = q->rear; j <= i;j--){
            q->a[j + 1] = q->a[j];
        }
        cout << "Inserting in queue" << endl;
        q->a[i] = ele;
        q->rear++;
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
        int x = q->a[q->front];
        cout << "Popped element from queue: " << x << endl;
        q->front++;
    }
}

int main()
{
    int choice, element;
    queue q;
    q.rear = -1;
    q.front = 0;

    while (1)
    {
        cout << "\n-----------------" << endl
             << "Welcome to queue program." << endl
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