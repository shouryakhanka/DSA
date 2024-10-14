#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

Node *first = new Node;

void create(int A[], int n)
{

    Node *last;

    first->data = A[0];
    first->next = first;
    last = first;

    for (int i = 1; i < n; i++)
    {
        Node *t = new Node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void displayCircular()
{
    Node *p = first;

    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != first);
}

void displayCircularRecur(Node *p)
{
    static int flag = 0;

    if (p != first || flag == 0)
    {
        flag = 1;
        cout << p->data << " ";
        displayCircularRecur(p->next);
    }

    flag = 0;
}

int length(struct Node *p)
{
    int c = 0;

    do
    {
        c++;
        p = p->next;
    } while (p != first);

    return c;
}

int Deletion(Node *p, int pos)
{
    if (pos < 0 || pos > length(first))
        return -1;

    int x = 0;

    if (pos == 1)
    {
        while (p->next != first)
        {
            p = p->next;
        }

        if (p == first)
        {
            x = first->data;
            delete first;
            first = NULL;
            return x;
        }

        else
        {
            p->next = first->next;
            x = first->data;
            delete first;
            first = p->next;
            return x;
        }
    }

    else
    {
        for (int i = 0; i < pos - 2; i++)
        {
            p = p->next;
        }

        Node *q = p->next;
        p->next = q->next;
        x = q->data;
        delete q;
        return x;
    }
}

void Insertion(Node *p, int pos, int x)
{
    if (pos < 0 || pos > length(first))
        return;

    Node *t = new Node;
    t->data = x;
    if (pos == 0)
    {
        if (p == NULL)
        {
            p = t;
            p->next = p;
        }

        else
        {
            while (p->next != first)
            {
                p = p->next;
            }

            p->next = t;
            t->next = first;
            first = t;
        }
    }

    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }

        t->next = p->next;
        p->next = t;
    }
}

int main()
{
    int A[] = {2, 4, 6, 8, 10};
    create(A, 5);
    cout << Deletion(first, 4) << endl;
    displayCircularRecur(first);

    return 0;
}