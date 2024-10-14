// https://leetcode.com/problems/first-missing-positive/submissions/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int firstMissingPositive(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    int m = nums[nums.size() - 1];
    int s, e, mid;
    bool found;

    if (m <= 0)
        return 1;

    for (int key = 1; key < m; key++)
    {
        s = 0, e = nums.size() - 1;
        found = 0;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            if (nums[mid] == key)
            {
                found = 1;
                break;
            }

            else if (nums[mid] > key)
            {
                e = mid - 1;
            }

            else
            {
                s = mid + 1;
            }
        }
        if (!found)
        {
            return key;
        }
    }
    return m + 1;
}

void swap(vector<int> &nums, int first, int second)
{
    int temp = nums[first];
    nums[first] = nums[second];
    nums[second] = temp;
}

// time: O(n), space: O(1)
// simple cycle sort and then searching, continous range 1 to n
// apply cycle sort (first missing positive)
int firstMissingPositive1(vector<int> &nums)
{
    int i = 0;
    while (i < nums.size())
    {
        int correct = nums[i] - 1;
        if (nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[correct])
        {
            swap(nums, i, correct);
        }
        else
        {
            i++;
        }
    }

    // search for missing no.
    for (int index = 0; index < nums.size(); index++)
    {
        if (nums[index] != index + 1)
        {
            return index + 1;
        }
    }

    // case 2
    return nums.size() + 1;
}

int main()
{
    vector<int> nums = {3, 4, -1, 1};
    cout << firstMissingPositive1(nums) << endl;
    return 0;
}