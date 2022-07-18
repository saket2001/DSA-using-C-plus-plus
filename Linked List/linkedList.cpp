/*
    Singly Linked List
*/
#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct ll
{
    node *start;
} ll;

int isEmpty(ll *ll)
{
    return ll->start == NULL ? 1 : 0;
}

int count(ll *ll)
{
    node *p;
    int count = 0;
    if (isEmpty(ll))
        cout << "Linked list is empty" << endl;
    else
    {
        p = ll->start;
        while (p != NULL)
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
        p = ll->start;
        while (p != NULL)
        {
            cout << p->data << "\t";
            p = p->next;
        }
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

    if (isEmpty(ll))
        ll->start = newNode;
    else
    {
        newNode->next = ll->start;
        ll->start = newNode;
        display(ll);
    }
}

void insertEnd(ll *ll, int ele)
{
    node *newNode = createNewNode(ele);
    node *p;

    if (isEmpty(ll))
        ll->start = newNode;
    else
    {
        p = ll->start;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = newNode;
        display(ll);
    }
}

void insertAtAny(ll *ll, int ele, int position)
{
    node *newNode = createNewNode(ele);
    node *p, *q;

    if (isEmpty(ll))
        ll->start = newNode;
    else if (position > count(ll) + 1)
        cout << "Invalid position. Choose another position below " << count(ll) + 1 << endl;
    else
    {
        // 5 10 _ 20 25
        p = ll->start;
        for (int i = 1; i < position - 1; i++)
            p = p->next;
        q = p->next;
        p->next = newNode;
        newNode->next = q;
        display(ll);
    }
}

void deleteStart(ll *ll)
{
    node *p;
    if (isEmpty(ll))
        cout << "Linked list is empty" << endl;
    else if (ll->start->next == NULL)
    {
        p = ll->start;
        ll->start == NULL;
        free(p);
    }
    else
    {
        p = ll->start;
        ll->start = p->next;
        free(p);
    }
    display(ll);
}

void deleteEnd(ll *ll)
{
    node *p, *q;
    if (isEmpty(ll))
        cout << "Linked list is empty" << endl;
    else if (ll->start->next == NULL)
    {
        p = ll->start;
        ll->start == NULL;
        free(p);
    }
    else
    {
        q = ll->start;
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

void deleteAtAny(ll *ll, int position)
{
    node *p, *q;

    if (isEmpty(ll))
        cout << "Linked is empty" << endl;
    else if (ll->start->next == NULL)
    {
        p = ll->start;
        ll->start == NULL;
        free(p);
    }
    else
    {
        q = ll->start;
        for (int i = 1; i < position - 1; i++)
            q = q->next;

        p = q->next;
        q->next = p->next;
        free(p);
        display(ll);
    }
}

void reverseLinkedList(ll *ll)
{
    node *p, *q, *r;
    if (isEmpty(ll))
        cout << "linked list is empty" << endl;
    else
    {
        p = ll->start;
        q = NULL;
        while (p != NULL)
        {
            r = p->next;
            p->next = q;
            q = p;
            p = r;
        }
        ll->start = q;
        cout << "Linked list reversed" << endl;
        display(ll);
    }
}

int main()
{
    int choice, element, pos;
    ll ll;
    ll.start = NULL;
    while (1)
    {
        cout << "\n-----------------" << endl
             << "Welcome to simple linear linked list program." << endl
             << "Select any one operation to continue: \n"
             << "1. Display linked list \n2. Insert in linked list an element from start \n3. Insert in linked list an element from end \n4. Insert in linked list an element from any position \n5.Remove an element from start in linked list \n6.Remove an element from end in linked list \n7.Remove an element from any position in linked list \n8.Count elements in linked list. \n9.Reverse the linked list \n10.Exit the program \n"
             << "-----------------" << endl;
        cin >> choice;

        if (choice == 10)
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
            cout << "Total elements in linked: " << count(&ll) << endl;
            cout << "Enter an element and position to add in linked list in any position:" << endl;
            cin >> element >> pos;
            insertAtAny(&ll, element, pos);
            break;
        case 5:
            deleteStart(&ll);
            break;
        case 6:
            deleteEnd(&ll);
            break;
        case 7:
            cout << "Total elements in linked: " << count(&ll) << endl;
            cout << "Enter a position of element to delete in linked list:" << endl;
            cin >> pos;
            deleteAtAny(&ll, pos);
            break;
        case 8:
            cout << "Total elements in linked: " << count(&ll) << endl;
            break;
        case 9:
            reverseLinkedList(&ll);
            break;
        default:
            cout << "You entered a wrong choice. Please select again!!" << endl;
            break;
        }
    }

    return 0;
}