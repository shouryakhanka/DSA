#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int maximumPopulation(vector<vector<int>> &logs)
    {
        vector<int> year(101, 0);

        for (auto log : logs)
        {
            year[log[0] - 1950]++;
            year[log[1] - 1950]--;
        }

        // calculating the prefix sum
        int max = year[0], yr = 0;

        for (int i = 1; i < 101; i++)
        {
            year[i] = year[i] + year[i - 1];

            if (year[i] > max)
            {
                max = year[i];
                yr = i + 1950;
            }
        }

        return yr;
    }

    int maximumPopulation2(vector<vector<int>> &logs)
    {
        unsigned int len = logs.size();
        unordered_map<int, int> yearRate;
        int minYear = logs[0][0], maxYear = logs[0][1];
        // here we'll add each year we encounter to the map
        // add 1 to it if someone was born, and subtract 1 if someone died
        for (const vector<int> &lifespan : logs)
        {
            yearRate[lifespan[0]]++;
            yearRate[lifespan[1]]--;
            minYear = min(minYear, lifespan[0]);
            maxYear = max(maxYear, lifespan[1]);
        }
        int maxPop = 0, currPop = 0, maxPopYear = minYear;
        // We only need to iterate from the earliest year to the last year
        for (int i = minYear; i < maxYear; i++)
        {
            auto iter = yearRate.find(i);
            // If the year is in the map, update the current population
            if (iter != yearRate.end())
            {
                currPop += iter->second;
                // If the current population is the maximum so far,
                // update the maximum population variables
                if (currPop > maxPop)
                {
                    maxPop = currPop;
                    maxPopYear = i;
                }
            }
        }
        return maxPopYear;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> logs = {{1993, 1999}, {2000, 2010}};

    cout
        << sol.maximumPopulation2(logs);

    return 0;
}