// https://leetcode.com/problems/rotate-array/description/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// time: O(n), space: O(1)

vector<int> rotate(vector<int> &nums, int k)
{
    if (k > nums.size())
        k = k % nums.size();

    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());

    return nums;
}

// time: O(n), space: O(1)
void reverse1(vector<int> &nums, int l, int h)
{
    while (l < h)
    {
        int temp = nums[l];
        nums[l] = nums[h];
        nums[h] = temp;

        l++;
        h--;
    }
}

vector<int> rotate1(vector<int> &nums, int k)
{
    if (k >= nums.size())
        k = k % nums.size();

    reverse1(nums, 0, (nums.size() - 1 - k));
    reverse1(nums, nums.size() - k, nums.size() - 1);
    reverse1(nums, 0, nums.size() - 1);

    return nums;
}
// time: O(n), space: O(n)
void rotateArray2(vector<int> nums, int n, int k)
{
    if (n < 0 || k < 1)
        return;

    // make a copy of the original vector

    vector<int> numsCopy(n);

    // copy the elements of nums to new vector
    for (int i = 0; i < n; i++)
    {
        numsCopy[i] = nums[i];
    }

    for (int i = 0; i < n; i++)
    {
        nums[(i + k) % n] = numsCopy[i];
    }
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    vector<int> ans = rotate(nums, k);

    for (int i : ans)
    {
        cout << i << " ";
    }
    return 0;
}