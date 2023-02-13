#include <iostream>
#include <string>

using namespace std;

bool isPalindorme(int num)
{
    int originalN = num;
    int reverse = 0;
    while (num > 0)
    {
        int lastDigit = num % 10;
        reverse = reverse * 10 + lastDigit;
        num = num / 10;
    }
    return reverse == originalN;
}

// in case of strings

bool isPalindrome1(string s)
{
    int n = s.size();

    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - i - 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cout << isPalindrome1("shourya") << endl;
    return 0;
}