// https://leetcode.com/problems/single-element-in-a-sorted-array/description/

#include <iostream>
#include <vector>

using namespace std;

int singleNonDuplicate(vector<int> &nums)
{
    int start = 0;
    int end = nums.size() - 1;

    while (start < end)
    {
        int mid = start + (end - start) / 2;

        if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 == 1 && nums[mid] == nums[mid - 1]))
        {
            start = mid + 1;
        }

        else
        {
            end = mid;
        }
    }
    return nums[start];
}

int main()
{
    vector<int> nums = {3, 3, 7, 7, 10, 11, 11};
    cout << singleNonDuplicate(nums) << endl;
    return 0;
}