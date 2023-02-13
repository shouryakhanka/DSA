#include <iostream>
#include <cmath>

using namespace std;

int fact(int n)
{
    int fact = 1;
    for (int i = n; i > 0; i--)
    {
        fact *= i;
    }
}

int rem(int n)
{
    // if (n % 10 == n)
    //     return n;

    // int r = n % 10;

    // n = n / 10;

    // return r * rem(n);
    int pro = 1;
    while (n > 0)
    {
        int rem = n % 10;
        pro *= rem;
        n = n / 10;
    }
    return pro;
}

// reverse a number

// int sum = 0;
// int rev(int n)
// {
//     while (n > 0)
//     {

//         int rem = n % 10;

//         sum = sum * 10 + rem;

//         n = n / 10;
//     }
//     return sum;
// }

// performing reverse of a number using only the function

int helper(int n, int digits)
{
    if (n % 10 == n)
        return n;

    int rem = n % 10;

    return rem * pow(10, digits - 1) + helper(n / 10, digits - 1);
}

int rev1(int n)
{
    int digits = log10(n) + 1;

    return helper(n, digits);
}

int main()
{
    cout << rev1(5689) << endl;
    return 0;
}