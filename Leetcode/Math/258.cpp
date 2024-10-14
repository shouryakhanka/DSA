#include <iostream>
using namespace std;

int repeatAdd(int num)
{
    int sum = 0;
    int count = 0;

    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }

    if (sum < 10)
        return sum;

    return repeatAdd(sum);
}

int addDigits(int num)
{
    if (num == 0)
        return 0;

    return repeatAdd(num);
}

int main()
{
    int num = 0;
    cout << addDigits(0);
    return 0;
}