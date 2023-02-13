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

int main()
{
    vector<int> nums = {3, 2, 1, 0, 4};
    cout << canJump(nums) << endl;
    return 0;
}
