/*
    Singly Linked List
*/

// !Error half remaining

#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct ll
{
    node *last;
} ll;

int isEmpty(ll *ll)
{
    return ll->last == NULL ? 1 : 0;
}

int count(ll *ll)
{
    node *p;
    int count = 0;
    if (isEmpty(ll))
        cout << "Linked list is empty" << endl;
    else
    {   
        // 10 20 30
        p = ll->last;
        while (p != p)
        {
            count++;
            p = p->next;
        }
    }
    return count;
}

void display(ll *ll)
{
    node *p;
    if (isEmpty(ll))
        cout << "Linked list is empty" << endl;
    else
    {
        cout << "Displaying Linked list" << endl;
        p = ll->last->next;
        do
        {
            cout << p->data << "\t";
            p = p->next;
        } while (p != ll->last->next);
    }
}

node *createNewNode(int ele)
{
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    newNode->next = NULL;
    newNode->data = ele;
    return newNode;
}

void insertStart(ll *ll, int ele)
{
    node *newNode = createNewNode(ele);

    if (isEmpty(ll)){
        ll->last = newNode;
        newNode->next = newNode;
    }
    else
    {
        // 0->5 10 20
        newNode->next = ll->last->next;
        ll->last->next = newNode;
        display(ll);
    }
}

void insertEnd(ll *ll, int ele)
{
    node *newNode = createNewNode(ele);
    node *p;

    if (isEmpty(ll))
        ll->last = newNode;
    else
    {
        p = ll->last;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = newNode;
        display(ll);
    }
}

void deleteStart(ll *ll)
{
    node *p;
    if (isEmpty(ll))
        cout << "Linked list is empty" << endl;
    else if (ll->last->next == NULL)
    {
        p = ll->last;
        ll->last == NULL;
        free(p);
    }
    else
    {
        p = ll->last;
        ll->last = p->next;
        free(p);
    }
    display(ll);
}

void deleteEnd(ll *ll)
{
    node *p, *q;
    if (isEmpty(ll))
        cout << "Linked list is empty" << endl;
    else if (ll->last->next == NULL)
    {
        p = ll->last;
        ll->last == NULL;
        free(p);
    }
    else
    {
        q = ll->last;
        while (q->next->next != NULL)
        {
            q = q->next;
        }
        p = q->next;
        q->next == NULL;
        free(p);
    }
    display(ll);
}

int main()
{
    int choice, element, pos;
    ll ll;
    ll.last = NULL;
    while (1)
    {
        cout << "\n-----------------" << endl
             << "Welcome to circular linked list program." << endl
             << "Select any one operation to continue: \n"
             << "1. Display linked list \n2. Insert in linked list an element from start \n3. Insert in linked list an element from any position \n4.Remove an element from start in linked list \n5.Remove an element from end in linked list \n6.Count elements in linked list. \n7.Exit the program \n"
             << "-----------------" << endl;
        cin >> choice;

        if (choice == 7)
        {
            cout << "\nYou exited the program" << endl;
            break;
        }

        switch (choice)
        {

        case 1:
            display(&ll);
            break;
        case 2:
            cout << "Enter an element to add in linked list in start:" << endl;
            cin >> element;
            insertStart(&ll, element);
            break;
        case 3:
            cout << "Enter an element to add in linked list in end:" << endl;
            cin >> element;
            insertEnd(&ll, element);
            break;
        case 4:
            deleteStart(&ll);
            break;
        case 5:
            deleteEnd(&ll);
            break;
        case 6:
            cout << "Total elements in linked: " << count(&ll) << endl;
            break;
        default:
            cout << "You entered a wrong choice. Please select again!!" << endl;
            break;
        }
    }

    return 0;
}