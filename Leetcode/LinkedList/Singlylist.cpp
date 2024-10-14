#include <iostream>
#include <climits>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
} *first;

class Linkedlist
{

public:
    Linkedlist(int A[], int n);
    ~Linkedlist();
    void display();
    void Insertion(int index, int key);
    int count(Node *p);
    void displayCircular();
    void displayCircularRecur(Node *p);
};

Linkedlist ::Linkedlist(int A[], int n)
{
    Node *last;

    if (n == 0)
    {
        return;
    }

    first = new Node();
    first->data = A[0];
    first->next = nullptr;

    Node *t;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = new Node();
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }

    last->next = first;
}

Linkedlist ::~Linkedlist()
{
    Node *p = first;

    while (first)
    {
        first = first->next;
        delete p;
        p = first;
    }
}

// void create2(int A[], int n)
// {
//     if (n == 0)
//     {
//         return;
//     }

//     second = new Node();
//     second->data = A[0];
//     second->next = nullptr;

//     Node *t;
//     last = second;

//     for (int i = 1; i < n; i++)
//     {
//         t = new Node();
//         t->data = A[i];
//         t->next = NULL;
//         last->next = t;
//         last = t;
//     }
// }

void Linkedlist ::display()
{
    Node *p = first;

    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

int sum = 0;

int Sum(Node *p)
{
    if (p == NULL)
    {
        return 0;
    }

    else
        return p->data + Sum(p->next);
}

int maxElement(struct Node *p)
{

    if (p == NULL)
        return INT_MIN;

    else
    {
        int x;

        x = maxElement(p->next);

        if (x > p->data)
            return x;

        return p->data;
    }
}

Node *Search(struct Node *p, int key)
{
    while (p)
    {
        if (key == p->data)
            return p;

        p = p->next;
    }
    return NULL;
}

bool RSearch(struct Node *p, int key)
{
    if (p == NULL)
        return false;

    if (key == p->data)
        return true;

    return RSearch(p->next, key);
}

// Node *ImprovedLinear(struct Node *p, int key)
// {
//     Node *q = NULL;

//     while (p != NULL)
//     {
//         if (key == p->data)
//         {
//             q->next = p->next;
//             p->next = second;
//             second = p;
//             return p;
//         }
//         q = p;
//         p = p->next;
//     }
//     return NULL;
// }

int Linkedlist ::count(struct Node *p)
{
    int c = 0;

    while (p)
    {
        c++;
        p = p->next;
    }
    return c;
}

void Linkedlist ::Insertion(int index, int key)
{
    Node *p = first;

    if (index < 0 || index > count(first))
    {
        return;
    }

    Node *t = new Node();
    t->data = key;

    if (index == 0)
    {
        t->next = first;
        first = t;
    }

    else
    {
        int x = index - 1;

        while (x--)
        {
            p = p->next;
        }

        t->next = p->next;
        p->next = t;
    }
}

// void InsertAtLast(struct Node *p, int x)
// {
//     Node *t = new Node();

//     t->data = x;
//     t->next = NULL;

//     if (second == NULL)
//     {
//         second = last = t;
//     }

//     else
//     {
//         last->next = t;
//         last = t;
//     }
// }

// void InsertInSorted(struct Node *p, int x)
// {
//     Node *q = NULL;
//     Node *t = new Node();
//     t->data = x;
//     t->next = NULL;

//     if (second == NULL)
//     {
//         second = t;
//     }

//     else
//     {

//         while (p && p->data < x)
//         {
//             q = p;
//             p = p->next;
//         }

//         if (p == second)
//         {
//             t->next = p;
//             second = t;
//         }

//         else
//         {
//             q->next = t;
//             t->next = p;
//         }
//     }
// }

// void DeleteFirst()
// {
//     Node *p = new Node();
//     p = second;

//     second = second->next;
//     delete p;
// }

// int DeletePos(struct Node *p, int pos)
// {
//     Node *q = NULL;
//     int x = 0;

//     if (pos < 1 || pos > count(p))
//         return -1;

//     if (pos == 1)
//     {
//         q = p;
//         p = p->next;
//         second = p;
//         x = q->data;
//         delete q;
//         return x;
//     }

//     else
//     {
//         for (int i = 0; i < pos - 1; i++)
//         {
//             q = p;
//             p = p->next;
//         }

//         q->next = p->next;
//         x = p->data;
//         delete p;
//         return x;
//     }
// }

// bool checkSorted(Node *p)
// {
//     int x = INT_MIN;

//     while (p)
//     {
//         if (p->data < x)
//         {
//             return false;
//         }
//         x = p->data;
//         p = p->next;
//     }
//     return true;
// }

// void remDulplicate(Node *p)
// {
//     Node *q = p->next;

//     while (q)
//     {
//         if (p->data != q->data)
//         {
//             p = q;
//             q = q->next;
//         }

//         else
//         {
//             p->next = q->next;
//             delete q;
//             q = p->next;
//         }
//     }
// }

// void reverseList(Node *p)
// {
//     int n = count(p);
//     int A[n];
//     int i = 0;

//     while (p)
//     {
//         A[i++] = p->data;
//         p = p->next;
//     }

//     p = second;
//     i--;

//     while (p)
//     {
//         p->data = A[i--];
//         p = p->next;
//     }
// }

// void reversePointers(Node *p)
// {
//     Node *q = nullptr;
//     Node *r = nullptr;

//     while (p)
//     {
//         r = q;
//         q = p;
//         p = p->next;
//         q->next = r;
//     }

//     second = q;
// }

// void recursionReverse(Node *q, Node *p)
// {

//     if (p != NULL)
//     {
//         recursionReverse(p, p->next);
//         p->next = q;
//     }

//     else
//     {
//         second = q;
//     }
// }

// void concatList(Node *first, Node *second)
// {
//     while (first->next)
//     {
//         first = first->next;
//     }

//     first->next = second;
//     second = NULL;
// }

// void merge(Node *first, Node *second)
// {
//     Node *third, *last;

//     if (first->data < second->data)
//     {
//         third = last = first;
//         first = first->next;
//         last->next = NULL;
//     }

//     else if (second->data < first->data)
//     {
//         third = last = second;
//         second = second->next;
//         last->next = NULL;
//     }

//     else
//     {
//         third = last = second;
//         second = second->next;
//         last->next = NULL;
//     }

//     while (first && second)
//     {
//         if (first->data < second->data)
//         {
//             last->next = first;
//             last = first;
//             first = first->next;
//             last->next = NULL;
//         }

//         else
//         {
//             last->next = second;
//             last = second;
//             second = second->next;
//             last->next = NULL;
//         }
//     }

//     if (first)
//     {
//         last->next = first;
//     }

//     if (second)
//     {
//         last->next = second;
//     }
// }

// Floyd’s cycle finding algorithm or Hare-Tortoise algorithm
bool isLoop(Node *p)
{
    Node *q = first;

    do
    {
        p = p->next;
        q = q->next;

        q = q ? q->next : q;
    } while (p && q && p != q);

    if (p == q)
        return true;

    else
        return false;
}

void Linkedlist ::displayCircular()
{
    Node *p = first;

    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != first);
}

int main()
{
    int A[] = {2, 5, 7, 9, 11};
    // int B[] = {2, 5, 7, 9, 11};

    Linkedlist l(A, 5);
    l.displayCircularRecur(first);
    // Node *t1, *t2;
    // t1 = first->next->next;
    // t2 = first->next->next->next->next;

    // t2->next = t1;

    // create2(B, 4);

    // l.display(first);
    // cout << endl;

    return 0;
}