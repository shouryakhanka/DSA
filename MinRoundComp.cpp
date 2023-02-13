// https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class MinRoundComp
{
public:
    int minimumRounds(vector<int> &tasks)
    {
        unordered_map<int, int> freq;

        for (int task : tasks)
        {
            freq[task]++;
        }

        int minimumRounds = 0;

        for (auto it : freq)
        {
            int task = it.first;
            int count = it.second;

            // is frequency is 1, it is not possible to complete the task
            if (count == 1)
                return -1;

            else if (count % 3 == 0)
                // group all the tasks in triplets
                minimumRounds += count / 3;

            else
            {
                // if count % 3 == 1, (count / 3 - 1) group of triplets and 2 pairs
                // if count % 3 == 2, (count / 3) group of triplets and 1 pair
                minimumRounds += count / 3 + 1;
            }
        }

        return minimumRounds;
    }
};

int main()
{
    MinRoundComp min_round_comp;
    vector<int> tasks = {2,2,3,3,2,4,4,4,4,4};

    cout << min_round_comp.minimumRounds(tasks) << endl;

    return 0;
}
