#include <iostream>
using namespace std;

int fact(int n)
{
    if (n == 0 || n == 1)
        return n;

    return fact(n - 1) * n;
}

int Ifact(int n)
{
    int f = 1;
    for (int i = 1; i <= n; i++)
    {
        f = f * i;
    }
    return f;
}

int main()
{
    cout << Ifact(6);
    return 0;
}