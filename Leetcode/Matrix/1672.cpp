#include <iostream>
#include <vector>

using namespace std;

int maximumWealth(vector<vector<int>> &accounts)
{
    int n = accounts.size();
    int m = accounts[0].size();

    int max = INT8_MIN;

    for (auto &row : accounts)
    {
        int sum = 0;
        for (auto &col : row)
        {
            sum += col;
        }

        if (max < sum)
            max = sum;
    }
    return max;
}

int main()
{
    vector<vector<int>> accounts = {{1, 5}, {7, 3}, {3, 5}};
    cout << maximumWealth(accounts) << endl;
    return 0;
}