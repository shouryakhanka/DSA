#include <iostream>
using namespace std;

struct term
{
    int coeff;
    int exp;
};

struct poly
{
    int n;
    struct term *terms;
};

void create(struct poly *p)
{
    cout << "Enter the no. of elements\n";
    cin >> p->n;

    p->terms = new term[p->n];

    cout << "Enter the terms";
    for (int i = 0; i < p->n; i++)
    {
        cin >> p->terms[i].coeff >> p->terms[i].exp;
    }
};

struct poly *add(struct poly *p1, struct poly *p2)
{
    struct poly *sum;
    sum = new poly;

    sum->n = p1->n + p2->n;

    sum->terms = new term[sum->n];

    int i = 0, j = 0, k = 0;

    while (i < p1->n && j < p2->n)
    {
        if (p1->terms[i].exp < p2->terms[j].exp)
        {
            sum->terms[k++] = p2->terms[j++];
        }

        else if (p1->terms[i].exp > p2->terms[j].exp)
        {
            sum->terms[k++] = p1->terms[i++];
        }

        else
        {
            sum->terms[k].exp = p1->terms[i].exp;
            sum->terms[k++].coeff = p1->terms[i++].coeff + p2->terms[j++].coeff;
        }
    }

    for (; i < p1->n; i++)
    {
        sum->terms[k++] = p1->terms[i];
    }

    for (; j < p2->n; j++)
    {
        sum->terms[k++] = p2->terms[j];
    }

    sum->n = k;
    return sum;
}

void display(struct poly p)
{
    for (int i = 0; i < p.n; i++)
    {
        cout << p.terms[i].coeff << "x" << p.terms[i].exp << "+";
    }
}

int main()
{
    struct poly p1;
    struct poly p2;
    struct poly *sum;

    create(&p1);
    create(&p2);

    sum = add(&p1, &p2);

    display(p1);
    cout << endl;
    display(p2);
    cout << endl;
    display(*sum);

    delete[] p1.terms;
    delete[] p2.terms;
    delete[] sum->terms;
    delete sum;

    return 0;
}