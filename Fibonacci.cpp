#include <iostream>
#include <vector>

using namespace std;

int m[10];

int mfib(int n)
{
    if (n <= 1)
    {
        m[n] = n;
        return n;
    }

    else
    {
        if (m[n - 1] == -1)
            m[n - 1] = mfib(n - 1);

        if (m[n - 2] == -1)
            m[n - 2] = mfib(n - 2);

        return mfib(n - 2) + mfib(n - 1);
    }
}

int ItFib(int n)
{
    if (n <= 1)
        return n;

    int r = 0;
    int s0 = 0;
    int s1 = 1;

    for (int i = 2; i <= n; i++)
    {
        r = s0 + s1;

        s0 = s1;
        s1 = r;
    }
    return r;
}

int sumFib(int n)
{
    if (n <= 0)
        return 0;

    return fib(n) + sumFib(n - 1);
}

int fib(int n)
{
    if (n <= 1)
        return n;

    return fib(n - 2) + fib(n - 1);
}

int main()
{
    cout << sumFib(5) << endl;
    return 0;
}
