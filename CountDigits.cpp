// #include<iostream>
// using namespace std;

// int main() {
//     int num = 7;

//     int countDigits(int num) {
//         int count = 0;

//         while (num > 0) {

//         int digit = num / 10;

//         if (num % digit == 0) {
//             count++;
//         }

//         num /= 10;
//     }
//         return count;
//     }
// };

// int countDigits(int n) {
//     int originalN = n;
//     int count = 0;
//     while (n > 0) {
//         int digit = n % 10;
//         if (digit != 0 && originalN % digit == 0) count++;
//         n /= 10;
//     }
//     return count;
// }

bool isPrime(int n)
{
    if (n < 2)
    {
        return false;
    }
    else
    {
        for (int i = 2; i < sqrt(n); i++)
        {
            if (n % i == 0)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }
}

class Solution
{
public:
    int distinctPrimeFactors(vector<int> &nums)
    {
    }
};

#include <iostream>
using namespace std;
int main()
{
    return 0;
}