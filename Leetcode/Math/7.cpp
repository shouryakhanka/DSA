#include <iostream>
#include <math.h>

using namespace std;

int Digits(int x)
{
    int count = 0;

    while (x)
    {
        count++;
        x = x / 10;
    }

    return count;
}

int reverse3(int x)
{
    int d = Digits(x);
    int digit = d - 1;
    int sum = 0;

    while (x)
    {
        int n = x % 10;
        sum += n * pow(10, digit);
        digit--;
        x = x / 10;
    }
    return sum;
}

// Line 13: Char 29: runtime error: signed integer overflow: 964632435 * 10 cannot be represented in type 'int' (solution.cpp)
// SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:22:29
int reverse2(int x)

{
        int revN = 0, sum = 0;
        
        while (x)
        {
            int digit = x % 10;

            revN = digit + revN * 10;
            x = x / 10;
        }
        return revN;
}

int reverse(int n)
{
    bool neg = n < 0;
    n = abs(n);

    int ans = 0;
    int temp;
    while (n > 0)
    {
        temp = n % 10;
        // if ((double)INT_MAX / ans <= 10.0)
        //     return 0;
        ans *= 10;
        ans += temp;
        n /= 10;
    }

    if (!neg)
        return ans;
    return ans * -1;
}

int main()
{
    int n = 123;
    cout << reverse2(n);

    return 0;
}