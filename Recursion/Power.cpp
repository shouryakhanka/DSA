#include <iostream>
using namespace std;

int power(int m, int n)
{
    if (n == 0)
        return 1;

    return power(m, n - 1) * m;
}

int Ipower(int m, int n)
{
    int pro = 1;

    for (int i = 1; i <= n; i++)
    {
        pro *= m;
    }
    return pro;
}

int Ipower2(int m, int n)
{
    int pro = 1;

    if (n % 2 == 0)
    {
        m *= m;
        n /= 2;
        for (int i = 1; i <= n; i++)
        {
            pro *= m;
        }
        return pro;
    }
    else
    {
        m *= m;
        n = (n - 1) / 2;

        for (int i = 1; i <= n; i++)
        {
            pro *= m;
        }
        return m / 2 * pro;
    }
}

// optimized power function, less no. of multiplications
int power2(int m, int n)
{
    if (n == 0)
        return 1;

    if (n % 2 == 0)
    {
        return power2(m * m, n / 2);
    }
    else
    {
        return m * power2(m * m, (n - 1) / 2);
    }
}

int main()
{
    int num, pow;
    // cout << "Enter the number and the power:" << endl;
    // cin >> num >> pow;
    cout << Ipower2(2, 4);

    return 0;
}