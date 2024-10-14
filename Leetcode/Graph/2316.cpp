#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

typedef long long ll;

void dfs(int node, vector<int> &visited, unordered_map<int, vector<int>> adj, int &cnt)
{
    visited[node] = 1;
    cnt++;

    for (auto &i : adj[node])
    {
        if (visited[i] == 0)
            dfs(i, visited, adj, cnt);
    }
}

long long countPairs(int n, vector<vector<int>> &edges)
{
    ll ans = (ll)(n * (n - 1) / 2);
    // creating the adjacency list
    unordered_map<int, vector<int>> adj;

    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int> visited(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            int cnt = 0;
            dfs(i, visited, adj, cnt);
            ans -= ((cnt * (cnt - 1)) / 2);
        }
    }
    return ans;
}

int main()
{
    int n = 7;

    vector<vector<int>> edges = {{0, 2}, {0, 5}, {2, 4}, {1, 6}, {5, 4}};

    cout << countPairs(n, edges) << endl;

    return 0;
}