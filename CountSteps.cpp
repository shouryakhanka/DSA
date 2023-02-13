// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/

#include <iostream>
using namespace std;

int numberOfSteps(int num)
{
    int count = 0;
    while (num > 0)
    {

        if (num % 2 == 0)
        {
            num /= 2;
            count++;
        }

        else
        {
            num--;
            count++;
        }
    }
    return count;
}

// using recursion

int helper(int num, int steps)
{
    if (num == 0)
        return steps;

    if (num % 2 == 0)
    {
        helper(num / 2, steps + 1);
    }

    else
    {
        helper(num - 1, steps + 1);
    }
}
int numberOfSteps1(int num)
{
    return helper(num, 0);
}

int main()
{
    cout << numberOfSteps1(1) << endl;
    return 0;
}
