// https://leetcode.com/problems/search-in-rotated-sorted-array/

#include <iostream>
#include <vector>

using namespace std;

int search(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // if nums[mid] == target return the index

        if (nums[mid] == target)
            return mid;

        if (nums[low] <= nums[mid])
        {
            // if the target is present between nums[low] & nums[mid]

            if (target >= nums[low] && target <= nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        else
        {
            // the target is present between nums[mid] and nums[high]

            if (target >= nums[mid] && target <= nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    cout << search(nums, 3) << endl;

    return 0;
}