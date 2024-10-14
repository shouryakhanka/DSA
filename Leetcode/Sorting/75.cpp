#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// time complexity: O(n) && space: O(1)
// The code uses the two-pointer approach to partition the elements of the input vector nums into three groups: 0, 1, and 2. The while loop runs until the mid pointer reaches the high pointer, and in each iteration, it performs constant-time operations.

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

// code:
/*Make variable count0, count1, count2 for 0's, 1's and 2's respectively.
Traverse the array and count the number of 0's 1's and 2's.
Now overwrite the original array in order of 0's, 1's and 2's using the count variables.
Keeping a count of 0's 1's and 2's and updating the original array
Time complexity - O(N)*/

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

void sortColors3(vector<int> &nums)
{
    int n = nums.size();
    int count0, count1, count2;

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
    for (int i = count0; i < count0 + count1; i++)
    {
        nums[i] = 1;
    }
    for (int i = count0 + count1; i < count0 + count1 + count2; i++)
    {
        nums[i] = 2;
    }
}

int main()
{
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    sortColors3(nums);

    for (int i : nums)
    {
        cout << i << endl;
    }
    return 0;
}