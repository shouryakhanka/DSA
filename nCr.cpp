#include <iostream>
using namespace std;

int fact(int n)
{
    int fact = 1;
    for (int i = n; i > 0; i--)
    {
        fact *= i;
    }
}

int nCr(int n, int r)
{
    int t1, t2, t3;

    t1 = fact(n);
    t2 = fact(n - r);
    t3 = fact(r);

    return t1 / (t2 * t3);
}

int nCr2(int n, int r)
{
    if (r == 0 || n == r)
        return 1;

    else
    {
        return nCr2(n - 1, r - 1) + nCr2(n - 1, r);
    }
}
int main()
{
    cout << nCr2(5, 3) << endl;
    return 0;
}