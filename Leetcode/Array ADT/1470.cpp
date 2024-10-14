#include <iostream>
#include <vector>
using namespace std;

// google

class ShuffleTheArray
{
public:
    // time: O(n) && space: O(n)
    vector<int> shuffle(vector<int> &nums, int n)
    {

        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            ans.push_back(nums[i]);
            ans.push_back(nums[i + n]);
        }
        return ans;
    }

    vector<int> shuffle1(vector<int> &nums, int n)
    {

        for (int i = 0; i < nums.size(); i++)
        {
            int currNum = nums[i];
            int currPos = i;
            while (currNum > 0)
            {
                int newPos{};
                if (currPos < n)
                {
                    newPos = 2 * currPos;
                }
                else
                {
                    newPos = 2 * (currPos - n) + 1;
                }

                int newNum = nums[newPos];
                nums[newPos] = -currNum;
                currNum = newNum;
                currPos = newPos;
            }
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0)
                nums[i] = -1 * nums[i];
        }
        return nums;
    }
};

int main()
{
    ShuffleTheArray shuffle;
    vector<int> nums = {2, 5, 1, 3, 4, 7};
    int n = 3;

    vector<int> res = shuffle.shuffle1(nums, n);

    for (int i : res)
    {
        cout << i << " ";
    }
    return 0;
}