#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// time complexity: O(n) && space: O(1)

vector<int> sortColors(vector<int> &nums)
{
    int mid = 0, low = 0;
    int high = nums.size() - 1;

    while (mid <= high)
    {
        switch (nums[mid])
        {
        case 0:
            swap(nums[mid++], nums[low++]);
            break;

        case 1:
            mid++;
        case 2:
            swap(nums[mid], nums[high--]);
        }
    }
    return nums;
}

void sortColors1(vector<int> &nums)
{
    int n = nums.size();
    int count0, count1, count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
            count0++;

        else if (nums[i] == 1)
            count1++;

        else
            count2++;
    }

    for (int i = 0; i < count0; i++)
    {
        nums[i] = 0;
    }

    for (int i = 0; i < count1; i++)
    {
        nums[i + count0] = 1;
    }

    for (int i = 0; i < count2; i++)
    {
        nums[i + count0 + count1] = 2;
    }
}

int main()
{
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    sortColors1(nums);

    for (int i : nums)
    {
        cout << i << endl;
    }
    return 0;
}