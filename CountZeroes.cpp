#include <iostream>
using namespace std;

int countZeroes(int num, int count)
{
    while (num > 0)
    {
        int lastDigit = num % 10;
        if (lastDigit == 0)
            count++;
        num = num / 10;

        countZeroes(num, count);
    }
    return count;
}

int main()
{
    cout << countZeroes(40404, 0) << endl;

    return 0;
}
