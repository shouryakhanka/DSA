#include <iostream>
#include <vector>

using namespace std;

// using the bruteforce approach
vector<int> searchRange1(vector<int> &nums, int target)
{
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++)
    {
        if (target == nums[i])
        {
            ans.push_back(i);
            break;
        }
    }

    for (int i = nums.size() - 1; i >= 0; i--)
    {
        if (target == nums[i])
        {
            ans.push_back(i);
            break;
        }
    }
    return ans;
}

vector<int> search(vector<int> nums, int target)
{
    vector<int> ans = {-1, -1};

    ans[0] = searchRange2(nums, target, true);

    if (ans[0] != -1)
        ans[1] = searchRange2(nums, target, false);

    vector<int> searchRange2(vector<int> & nums, int target, bool findStartIndex)
    {

        int low = 0;
        int high = nums.size() - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (target < nums[mid])
            {
                high = mid - 1;
            }
            else if (target > nums[mid])
            {
                low = mid + 1;
            }
            else
            {
                ans = mid;
                if (findStartIndex)
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
            vector<int> searchRange(vector<int> & nums, int target) int mini = -1;
            int maxi = -1;
            // start pos of target
            int low = 0;
            int high = nums.size() - 1;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                if (nums[mid] >= target)
                {
                    high = mid - 1;
                    if (nums[mid] == target)
                        mini = mid;
                }
                else
                {
                    low = mid + 1;
                }
            }
            // search for last pos of target
            low = 0;
            high = nums.size() - 1;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                if (nums[mid] <= target)
                {
                    low = mid + 1;
                    if (nums[mid] == target)
                        maxi = mid;
                }
                else
                {
                    high = mid - 1;
                }
            }
            return {mini, maxi};
        }

        int main()
        {
            vector<int> prob = {5, 7, 7, 8, 8, 10};
            int target = 8;
            vector<int> result = searchRange1(prob, target);

            for (int i : result)
            {
                cout << i << " ";
            }
            return 0;
        }