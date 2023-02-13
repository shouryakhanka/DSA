#include <iostream>
#include <vector>

using namespace std;

// time: O(n), space: O(1) if we don't take the output array as an
// additional space in space complexity analysis

vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();

    vector<int> res(n);
    int postfix = 1;
    int prefix = 1;
    for (int i = 0; i < n; i++)
    {
        res[i] = prefix;
        prefix *= nums[i];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        res[i] *= postfix;
        postfix *= nums[i];
    }
    return res;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    vector<int> ans = productExceptSelf(nums);

    for (int i : ans)
    {
        cout << i << " ";
    }
    return 0;
}