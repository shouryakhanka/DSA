// https://leetcode.com/problems/jump-game/

#include <iostream>
#include <vector>

using namespace std;
// try to solve the problem using dp
// just update the max index we can reach while iterating
// over the vector,

// case1 if we have starting index as 0, we can't move forward
//  case2 if we don't have zeroes we can always reach the end

// time : O(n) and space : O(1)

bool canJump(vector<int> &nums)
{
    int reachable = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (reachable < i)
            return false;

        reachable = max(reachable, i + nums[i]);
    }
    return true;
}

bool Jump2(vector<int> &nums)
{
    int count = 0;
    int reachable = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        // if (reachable < i)
        //     return false;

        reachable = max(reachable, i + nums[i]);
        count++;

        if (reachable == nums[n - 1])
            return count;
    }
    // return count;
}

// greedy approach with time: O(n), space: O(1)
bool Jump2(vector<int> &nums)
{
    int farthest = 0;
    int current = 0;
    int jumps = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        farthest = max(farthest, i + nums[i]);

        if (i == current)
        {
            current = farthest;
            jumps++;
        }
    }
    return jumps;
}

int main()
{
    vector<int> nums = {3, 2, 1, 0, 4};
    cout << canJump(nums) << endl;
    return 0;
}
