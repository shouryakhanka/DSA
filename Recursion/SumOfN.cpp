#include <iostream>
using namespace std;

int rSum(int n)
{
    if (n == 0)
        return 0;

    return rSum(n - 1) + n;
}

int Isum(int n)
{
    int s = 0;

    for (int i = 1; i <= n; i++)
    {
        s += i;
    }

    return s;
}

int main()
{
    cout << Isum(5);
    return 0;
}