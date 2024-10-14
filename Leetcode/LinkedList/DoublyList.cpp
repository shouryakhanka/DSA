#include <iostream>
using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;
};

Node *first = new Node;

void create(int A[], int n)
{
    Node *last;

    first->data = A[0];
    first->prev = NULL;
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        Node *t = new Node;

        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

int length(Node *p)
{
    int len = 0;

    while (p)
    {
        len++;
        p = p->next;
    }

    return len;
}

void Insertion(Node *p, int pos, int val)
{
    Node *t;

    if (pos < 0 || pos > length(p))
        return;

    if (pos == 0)
    {
        t = new Node;
        t->data = val;
        t->next = first;
        t->prev = NULL;
        first->prev = t;
        first = t;
    }

    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }

        t = new Node;
        t->data = val;
        t->next = p->next;
        t->prev = p;
        if (p->next)
            p->next->prev = t;
        p->next = t;
    }
}

int Deletion(Node *p, int pos)
{
    Node *t;
    int x = 0;

    if (pos < 1 || pos > length(p))
        return -1;

    if (pos == 1)
    {
        x = p->data;
        first = first->next;
        delete p;

        return x;
    }

    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }

        p->prev->next = p->next;
        if (p->next)
            p->next->prev = p->prev;
        x = p->data;
        delete p;
        return x;
    }
}

void display(Node *p)
{
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

void reverse(Node *p)
{
    while (p)
    {
        Node *temp = p->next;
        p->next = p->prev;
        p->prev = temp;

        if (p->prev == NULL)
            first = p;
    
    p = p->prev;
    }
}

int main()
{
    int A[] = {2, 4, 6, 7, 1, 3};
    create(A, 6);
    display(first);
    cout << endl;

    reverse(first);
    display(first);

    return 0;
}