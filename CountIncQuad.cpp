#include <iostream>
#include <vector>
using namespace std;

long long countQuadruplets(vector<int> &nums)
{
    int n = nums.size();

    int i = 0, j = 1, k = 2;
    int count = 0;

    for (int i = 3; i < n; i++)
    {
        int l = nums[i];

        if (nums[i] < nums[k])
        {
            if (nums[k] < nums[j])
            {
                if (nums[j] < nums[l])
                {
                    count++;
                }
            }
        }
    }
    return count;
}

int main()
{
    vector<int> nums = {1, 3, 2, 4, 5};
    cout << countQuadruplets(nums) << endl;
    return 0;
}