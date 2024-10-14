// https://leetcode.com/problems/house-robber/

#include <iostream>
#include <vector>

using namespace std;

// house robber using the recursion, it is performing incl and excl from end, we
// can do the same from the start, we have two choice only, if we incl it then
// go with n - 2, i.e not adjacent, if we excl it we can go with n - 1

// time: O(2 ^ n) && space: O(2 ^ n)
int solve(vector<int> &nums, int n, vector<int> dp)
{
    if (n < 0)
        return 0;

    if (n == 0)
        return nums[0];

    if (dp[n] != -1)
        return dp[n];

    int incl = solve(nums, n - 2, dp) + nums[n];
    int excl = solve(nums, n - 1, dp) + 0;

    dp[n] = max(incl, excl);

    return dp[n];
}

int rob(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);

    int ans = solve(nums, n - 1, dp);
}

// using memoization
int solve2(vector<int> &nums, int n, vector<int> dp)
{
    if (n < 0)
        return 0;

    if (n == 0)
        return nums[0];

    if (dp[n] != -1)
        return dp[n];

    int incl = solve(nums, n - 2, dp) + nums[n];
    int excl = solve(nums, n - 1, dp) + 0;

    dp[n] = max(incl, excl);

    return dp[n];
}

int solveTab(vector<int> &nums)
{
    int n = nums.size();

    if (n < 1)
        return -1;

    if (n == 1)
        return nums[0];

    vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++)
    {
        int incl = dp[i - 2] + nums[i];
        int excl = dp[i - 1] + 0;

        dp[i] = max(incl, excl);
    }

    return dp[n - 1];
}

int main()
{
    vector<int> nums = {114, 117, 207, 117, 235, 82, 90, 67, 143, 146, 53, 108, 200, 91, 80, 223, 58, 170, 110, 236, 81, 90, 222, 160, 165, 195, 187, 199, 114, 235, 197, 187, 69, 129, 64, 214, 228, 78, 188, 67, 205, 94, 205, 169, 241, 202, 144, 240};
    cout << solveTab(nums) << endl;
    return 0;
}
