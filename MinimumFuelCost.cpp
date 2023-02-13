#include <iostream>
#include <vector>
using namespace std;

class MinimumFuelCost
{
public:
    long long ans = 0;

    int dfs(vector<vector<int>> &v, int node, vector<int> &visited, int seats)
    {
        visited[node] = true;
        int cnt = 1;

        for (int i = 0; i < v[node].size(); i++)
        {
            int curr = v[node][i];

            if (!visited[curr])
                cnt += dfs(v, curr, visited, seats);
        }

        long long x = cnt / seats;

        if (cnt % seats)
            x++;

        if (node != 0)
            ans += x;

        return cnt;
    }

    long long minimumFuelCost(vector<vector<int>> &roads, int seats)
    {
        if (roads.size() == 0)
            return 0;

        int n = roads.size();

        vector<vector<int>> v(n + 1);

        for (auto &element : roads)
        {
            v[element[0]].push_back(element[1]);
            v[element[1]].push_back(element[0]);
        }

        vector<int> visited(n + 1, 0);

        dfs(v, 0, visited, seats);

        return ans;
    }
};

int main()
{
    MinimumFuelCost min;

    vector<vector<int>> roads = {{3, 1}, {3, 2}, {1, 0}, {0, 4}, {0, 5}, {4, 6}};
    int seats = 2;

    long long minimumFuelCost = min.minimumFuelCost(roads, seats);

    cout << minimumFuelCost << endl;

    return 0;
}