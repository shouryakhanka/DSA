#include <iostream>
#include <vector>
using namespace std;

class Solution
{

private:
    void dfs(vector<vector<int>> &adj, vector<bool> &visited, int src)
    {
        visited[src] = true;

        for (int i : adj[src])
        {
            if (!visited[i])
            {
                dfs(adj, visited, i);
            }
        }
    }

public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        vector<vector<int>> adj(n);
        int components = 0;

        for (auto i : connections)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(adj, visited, i);
                components++;
            }
        }
        return components - 1;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> connections = {{0, 1}, {0, 2}, {1, 2}};
    int n = 4;

    cout << sol.makeConnected(n, connections);

    return 0;
}