#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2)
    {
        int n = arr1.size();
        int i, x;
        vector<int> poss;

        for (i = 0; i < n; i++)
        {
            if (arr1[i + 1] < arr1[i])
            {
                x = i;

                for (int i = arr1[i - 1] + 1; i < arr1[i + 1]; i++)
                {
                    poss.push_back(i);
                }
            }
        }

        if (i == n)
        {
            return 0;
        }

        int y;

        for (int i = 0; i < poss.size(); i++)
        {
            if (count(arr2.begin(), arr2.end(), poss[i]))
            {
                y = poss[i];
                break;
            }
            else
            {
                continue;
            }
        }

        if (i == poss.size())
        {
            return -1;
        }

        arr1[x] = y;
    }
};

int main()
{
    return 0;
}