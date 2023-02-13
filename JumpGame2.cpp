#include <iostream>
#include <vector>
using namespace std;

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
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << canJump(nums) << endl;
    return 0;
}
