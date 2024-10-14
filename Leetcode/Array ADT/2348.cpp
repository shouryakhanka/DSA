#include <iostream>
using namespace std;

class Solution
{
public:
    long long zeroFilledSubarray(vector<int> &nums)
    {
        int cnt = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                cnt++;
        }
    }
};

int main()
{
    return 0;
}