#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> nums = {4,3,2,7,8,2,3,1};

    for (int i = 0; i < nums.size(); i++)
    {
        int count = 1;

        if (nums[i] != -1)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {

                if (nums[i] == nums[j])
                {
                    count++;
                    nums[j] = -1;
                }
            }
            cout << nums[i] << " " << count << endl;
        }
    }

    return 0;
}