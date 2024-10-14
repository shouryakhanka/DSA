#include <iostream>
#include<vector>

using namespace std;

class FindPeakEle {
public:
    int findPeakElement(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1])
                return i;
        }
        return nums.size() - 1;
    }
};

int main()
{
    vector<int> nums = {1,2,1,3,5,6,4};
    FindPeakEle find;
    cout << find.findPeakElement(nums);
    return 0;
}