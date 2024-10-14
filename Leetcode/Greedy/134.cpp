#include <iostream>
#include <vector>

using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int gasFuel = 0;
    int costFuel = 0;

    for (int i = 0; i < gas.size(); i++)
    {
        gasFuel += gas[i];
    }

    for (int i = 0; i < cost.size(); i++)
    {
        costFuel += cost[i];
    }

    if (gasFuel < costFuel)
    {
        return -1;
    }

    int current = 0;
    int start = 0;

    for (int i = 0; i < gas.size(); i++)
    {
        current += gas[i] - cost[i];

        while (current < 0)
        {
            start = start + i;
            current = 0;
        }
    }
    return start;
}

int main()
{
    vector<int> gas = {5, 1, 2, 3, 4};
    vector<int> cost = {4, 4, 1, 5, 1};

    cout << canCompleteCircuit(gas, cost) << endl;

    return 0;
}