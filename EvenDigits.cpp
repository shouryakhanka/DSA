
// https://leetcode.com/problems/find-numbers-with-even-number-of-digits/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> findEvenDigits(vector<int> nums)
{
    vector<int> even_digits;

    for (int num : nums)
    {
        string n = to_string(num);
        int len = n.length();

        if (len % 2 == 0)
        {
            even_digits.push_back(num);
        }
    }
    return even_digits;
}

int count(int n)
{
    if (n < 0)
        n *= -1;

    return log10(n) + 1;
}

// time: O(n * log(n)), space: O(n)
int findNumbers(vector<int> &nums)
{
    int even = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        int ans = count(nums[i]);

        if (ans % 2 == 0)
        {
            even++;
        }
    }
    return even;
}

int main()
{
    vector<int> nums = {555, 901, 482, 1771};

    cout << findNumbers(nums) << endl;

    // vector<int> even_digits = findEvenDigits(nums);

    // for (int no : even_digits)
    // {
    //     cout << "No. of even digits no.s";
    //     cout << " " << no;
    // }
    return 0;
}